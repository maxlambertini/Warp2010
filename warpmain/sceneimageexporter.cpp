/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

#include "sceneimageexporter.h"
#include "helpers/printingpreferences.h"
#include "helpers/sectorrectholder.h"
#include <QtGui>
#include <QtSvg>



void SceneImageExporter::ExportToSVG(QGraphicsScene *scene, QString fileName)
{
    QSvgGenerator *generator = new QSvgGenerator();
    generator->setResolution(72);
    generator->setSize(QSize(
            (int)scene->sceneRect().width(),
            (int)scene->sceneRect().height()));
    generator->setFileName(fileName);
    QPainter painter(generator);
    painter.setBrush(QColor("white"));
    scene->render(&painter);
}

void SceneImageExporter::ExportToPNG(QGraphicsScene *scene, QString fileName)
{
    QPixmap *pixmap = new QPixmap(
            (int)scene->sceneRect().width(),
            (int)scene->sceneRect().height());
    QPainter painter(pixmap);
    scene->render(&painter);
    painter.end();
    pixmap->save(fileName);
    delete pixmap;
}

void SceneImageExporter::printScene(QGraphicsScene *scene, QPrinter& printer,
                                    QString fileName, QString documentName,
                                    int printingFlags)
{

    if (!fileName.isEmpty() && fileName != "" && fileName.endsWith(".pdf",Qt::CaseInsensitive))
    {
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
    }
    else {
        //set page margins if I have to print on paper.
        printer.setPageMargins(QMarginsF(10,10,10,10),QPageLayout::Unit::Millimeter);
    }


    QPainter painter(&printer);

    QRectF sceneRect = scene->sceneRect();
    double sceneRatio = scene->sceneRect().width()/scene->sceneRect().height();
    qreal left,top,right,bottom;
    auto margins = printer.pageLayout().margins();
    left = margins.left();
    top = margins.top();
    right = margins.right();
    bottom = margins.bottom();
    QRect pageRect = QRect(
        printer.pageRect(QPrinter::DevicePixel).top()+top,
            printer.pageRect(QPrinter::DevicePixel).left()+left,
            printer.pageRect(QPrinter::DevicePixel).width()-(left+right),
            printer.pageRect(QPrinter::DevicePixel).height()-(top+bottom));

    int xSize, ySize, dxSize, dySize, xPages, yPages;
    double fWidth, fHeight, fHeightStep, fWidthStep;
    double pageRectRatio = (double)pageRect.width()/(double)pageRect.height();

    xSize = (int)((double)(3*pageRect.width()) * 1.0);
    ySize = (int)((double)(3*pageRect.height()) * .9);
    dxSize = (int)((double)(3*pageRect.width()) * .05);
    dySize = (int)((double)(3*pageRect.height()) * .05);

    xPages = 1+ (((int)sceneRect.width()) / xSize);
    yPages = 1+ (((int)sceneRect.height()) / ySize);

    if (SIEOptions::ScaleToSceneHeight(printingFlags)) {
        yPages = 1;
        xPages = 1+(int)( (double)yPages *sceneRatio);
        ySize = (int) ((double)scene->sceneRect().height()*.9);
        xSize = (int) ( (double)ySize * pageRectRatio);
        dySize = (int) (.05 * (double)scene->sceneRect().height()*.9);
        dxSize = (int) ( .05 *(double)ySize * pageRectRatio);

    }

    if (SIEOptions::ScaleToSceneWidth(printingFlags)) {
        xPages = 1;
        yPages = 1+(int)( (double)yPages / sceneRatio);
    }


    fWidth = 1.0* (double)pageRect.width();
    fHeight = .9* (double)pageRect.height();
    fHeightStep = .15* (double)pageRect.height();
    fWidthStep = fHeightStep * sceneRatio;

    bool bNewPage = false;
    double fWidth2 = fWidth * .9;
    double fHeight2 = fHeight * .9;

    QPainterPath path;
    QRectF rectOuter;
    rectOuter.setLeft((double)pageRect.left());
    rectOuter.setTop((double)pageRect.top());
    rectOuter.setWidth(fWidth2);
    rectOuter.setHeight(fHeight2);

    path.addRect(rectOuter);

    QRectF rectInner(rectOuter);
    rectInner.setTopLeft(QPointF(
            rectInner.left()+fWidth2/20,
            rectInner.top()+fHeight2/20));
    rectInner.setSize(QSizeF(fWidth2*.9,fHeight2*.9));
    path.addRect(rectInner);


    painter.begin(&printer);

    QBrush shadowBrush = QBrush(QColor(192,192,192,64));
    QBrush transparent = QBrush(QColor(192,192,192,16));
    //QPen pen = QPen(QColor (65,65,65,192));
    QPen pen = QPen(QColor (255,0,0,192));
    QFont font = QFont("Droid Sans");
    font.setBold(true);
    font.setPointSizeF(16.0);

    QFont fontb = QFont("Droid Sans");
    fontb.setBold(false);
    fontb.setPointSizeF(11.0);


    //double fh = fHeightStep / yPages;
    //double fw = fWidthStep / xPages;

    double tinyRectXRatio = fWidthStep / scene->sceneRect().width();
    double tinyRectYRatio = fHeightStep / scene->sceneRect().height();

    int nCur = 0;
    int nMax = yPages*xPages;

    for (int y = 0; y < yPages; y++) {
        for (int x = 0; x < xPages; x++) {
            nCur = (y*xPages)+(x+1);
            if (bNewPage)
                printer.newPage();
            else
                bNewPage = true;

            QRectF targetRect = QRectF((double)pageRect.left(),(double)pageRect.top(),fWidth2,fHeight2);

            QRectF sourceRect = QRectF (
                    (double)(x*xSize)+sceneRect.left()-(double)dxSize,
                    (double)(y*ySize)+sceneRect.top()-(double)dySize,
                    (double)(xSize)+2*(double)dxSize,
                    (double)(ySize)+2*(double)dySize);

            QRectF targetRect2 = QRectF(
                    (double)targetRect.left()+10,
                    (double)targetRect.top()+ fHeight2+10,
                    fWidthStep,
                    fHeightStep);

            QRectF tinyRect;
            tinyRect.setLeft((sourceRect.left()-sceneRect.left()) * tinyRectXRatio+targetRect2.left());
            tinyRect.setTop((sourceRect.top()-sceneRect.top()) * tinyRectYRatio+ targetRect2.top());
            tinyRect.setWidth(sourceRect.width()*tinyRectXRatio);
            tinyRect.setHeight(sourceRect.height()*tinyRectYRatio);


            scene->render(&painter,targetRect, sourceRect);
            painter.setPen(pen);
            painter.setBrush(transparent);
            painter.drawRect(targetRect2);

            scene->render(&painter,targetRect2, scene->sceneRect(), Qt::IgnoreAspectRatio);
            painter.setPen(pen);
            painter.setBrush(shadowBrush);
            painter.drawPath(path);
            painter.drawRect(tinyRect);

            QFontMetricsF metrics(font);

            int nDelta = 0;
            painter.setFont(font);
            painter.setBrush(QBrush(QColor("black")));
            painter.drawText(
                    targetRect2.left()+fWidthStep+10,
                    targetRect2.top()+metrics.height(),
                    documentName);

            nDelta+= (int)metrics.height()+10;

            painter.setFont(fontb);
            QFontMetricsF metricsb(fontb);
            nDelta+= (int)metricsb.height();
            QString txt = QString().asprintf("Folio [%d,%d] -- page %d of %d",x,y,nCur, nMax);
            painter.drawText(
                    targetRect2.left()+fWidthStep+10,
                    targetRect2.top()+nDelta,
                    txt);


        }
    }
    painter.end();
}

void SceneImageExporter::PageGraphicsSceneToPrinter(QGraphicsScene *scene, QPrinter &printer,
                                                    QList<SectorRectHolder>& pageRegions, QString fileName,
                                                    QString documentName __attribute__((unused)))
{
    PrintingPreferences &pref  __attribute__ ((unused))  = PrintingPreferences::prefs();
    //qDebug()  << pref.yDivisions();
    //qDebug()  << pref.selectedMeasure();
    //qDebug() << pref.measures();

    if (!fileName.isEmpty() && fileName != "" && fileName.endsWith(".pdf",Qt::CaseInsensitive))
    {
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
    }

    // When printing, use full page mode, IE ignore hardware margins. It's up
    // to users to set them as they desire.
    printer.setFullPage(true);
    // QPrinter::Millimeter
    printer.setPageSize(QPageSize(QSizeF(PrintingPreferences::prefs().selectedMeasure().width(),
                                         PrintingPreferences::prefs().selectedMeasure().height()),QPageSize::Millimeter));
    printer.setPageMargins(QMarginsF(PrintingPreferences::prefs().leftMargin(),
                           PrintingPreferences::prefs().topMargin(),
                           PrintingPreferences::prefs().rightMargin(),
                                     PrintingPreferences::prefs().bottomMargin()),
                           QPageLayout::Unit::Millimeter);

    //here, I print using selected sheets and divisions.
    QPainter painter(&printer);
    qreal left,top,right,bottom;
    auto margins = printer.pageLayout().margins();
    left = margins.left();
    top = margins.top();
    right = margins.right();
    bottom = margins.bottom();

    // get the FULL PAGE RECTANGLE and adjust margins.
    QRectF pageRect = printer.paperRect(QPrinter::DevicePixel);
    pageRect.adjust(left,top,-right, -bottom);


    QColor transparent(0,0,0,0);
    QColor transBorder (0,0,0,128);
    QPen pen (transBorder);
    pen.setStyle(Qt::DotLine);
    QBrush brush;

    QGraphicsScene sceneFirst;
    QPen pen2 (QColor(0,0,0));
    pen2.setStyle(Qt::DotLine);
    pen2.setWidthF(2.0);
    QBrush brush2;
    for (int h = 0; h < pageRegions.count(); h++)
    {
        QRectF rect = pageRegions[h].rectInner();
        sceneFirst.addRect (rect.left(), rect.top(), rect.width(),rect.height(),pen2, brush2);
        rect = pageRegions[h].rectOuter();
        sceneFirst.addRect (rect.left(), rect.top(), rect.width(),rect.height(),pen2, brush2);
    }
    scene->render(&painter, pageRect, scene->itemsBoundingRect(),Qt::KeepAspectRatio);
    sceneFirst.render(&painter,pageRect, sceneFirst.sceneRect(),Qt::KeepAspectRatio);


    for (int h = 0; h < pageRegions.count(); h++)
    {
        QRectF rect = pageRegions[h].rectOuter();
        double ratio = rect.width()/rect.height();
        QRectF rectTarget = QRectF(pageRect.left(), pageRect.top(), pageRect.width(), pageRect.width()/ratio);
        printer.newPage();
        scene->render(&painter,rectTarget, rect);
        painter.setPen(pen2);
        painter.setBrush(brush);
        painter.drawRect(rectTarget);
        QRectF rect2 = pageRegions[h].rectInner();
        double ratioX = rectTarget.width()/rect.width();
        double ratioY = rectTarget.height()/rect.height();

        double dy = rect2.top()-rect.top();
        double dx = rect2.left() - rect.left();

        //qDebug() << "rect outer: " << rect
        //        <<  "\nrect inner: " << rect2
        //        << "\nrect target: " << rectTarget
        //        << "\nx: " << dx << ",y:" << dy;

        QRectF rectTarget2 (rectTarget.top()+ dx*ratioX,
                            rectTarget.left()+dy*ratioY,
                            rect2.width()*ratioX,
                            rect2.height()*ratioY);
        painter.drawRect(rectTarget2);

    }
    painter.end();
}

void SceneImageExporter::GraphicsSceneToPrinter(
        QGraphicsScene *scene, QPrinter& printer,
        QString fileName, QString documentName __attribute__((unused)),
        bool bSizeToOneSheet)
{
    if (!fileName.isEmpty() && fileName != "" && fileName.endsWith(".pdf",Qt::CaseInsensitive))
    {
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
    }

    // When printing, use full page mode, IE ignore hardware margins. It's up
    // to users to set them as they desire.
    printer.setFullPage(true);
    printer.setPageSize(QPageSize(QSizeF(PrintingPreferences::prefs().selectedMeasure().width(),
                                         PrintingPreferences::prefs().selectedMeasure().height()), QPageSize::Millimeter));
    printer.setPageMargins(QMarginsF(PrintingPreferences::prefs().leftMargin(),
                           PrintingPreferences::prefs().topMargin(),
                           PrintingPreferences::prefs().rightMargin(),
                                     PrintingPreferences::prefs().bottomMargin()),
                           QPageLayout::Unit::Millimeter);


    if (!bSizeToOneSheet) {

        //here, I print using selected sheets and divisions.
        QPainter painter(&printer);
        qreal left,top,right,bottom;
        auto margins = printer.pageLayout().margins(); //getPageMargins(&left,&top,&right,&bottom,QPrinter::DevicePixel);
        left = margins.left();
        right = margins.right();
        top = margins.top();
        bottom = margins.bottom();

        // get the FULL PAGE RECTANGLE and adjust margins.
        QRectF pageRect = printer.pageLayout().fullRectPixels(printer.resolution()) ;
        pageRect.adjust(left,top,-right, -bottom);


        //get height/width page rect ratio
        double pageRatio = pageRect.width()/pageRect.height();

        //get scene rectangle and calculating pages.
        int stepY = PrintingPreferences::prefs().yDivisions();
        QRectF sceneRect = scene->sceneRect();
        double scene_dy = sceneRect.height()/( (double)stepY);
        double scene_dx = scene_dy * pageRatio;


        double o_scene_dx = scene_dx * 1.1;
        double o_scene_dy = scene_dy * 1.1;

        double o_rect_dx = pageRect.width() / 1.1;
        double o_rect_dy = pageRect.height() / 1.1;

        double odx = ( pageRect.width() -o_rect_dx)/2.0;
        double ody = (pageRect.height() - o_rect_dy)/ 2.0;

        QRectF pageRectInner = QRectF (pageRect.left() + odx,
                                       pageRect.top() + ody,
                                       o_rect_dx, o_rect_dy);

        int stepX = 1+ (int)(sceneRect.width() / scene_dx);

        //ok, calculated my boxes. NOW, let's print everything out.
        QColor transparent(0,0,0,0);
        QColor transBorder (0,0,0,128);
        QPen pen (transBorder);
        pen.setStyle(Qt::DotLine);
        QBrush brush(transparent);

        bool bNewPage = false;

        for (int y = 0; y < stepY; y++) {
            for (int x = 0; x < stepX; x++) {
                if (bNewPage)
                    printer.newPage();
                else
                    bNewPage = true;

                //I've already got my target rectangle
                QRectF sourceRect = QRectF (
                        sceneRect.left()+((double)x * scene_dx  + (o_scene_dx - scene_dx)/2.0 ),
                        sceneRect.top()+((double)y * scene_dy + (o_scene_dy - scene_dy)/2.0),
                        o_scene_dx,o_scene_dy);


                scene->render(&painter,pageRect, sourceRect);

                QBrush oldBrush = painter.brush();
                QPen oldPen = painter.pen();

                //qDebug() << "pageRect " << pageRect;
                //qDebug() << "pageRectInner " << pageRectInner;

                painter.setPen(pen);
                painter.setBrush(brush);
                painter.drawRect(pageRect);
                painter.drawRect(pageRectInner);

                painter.setPen(oldPen);
                painter.setBrush(oldBrush);

            }
        }
        painter.end();
    }
    else {
        QRectF sceneRect = scene->sceneRect();
        //qDebug() << "scene Rect:" << sceneRect;
        printer.setResolution(96);
        printer.setPageSize(QPageSize(QSizeF(
                scene->sceneRect().width()+(76*2),
                                          scene->sceneRect().height()+(10*2)),QPageSize::Millimeter));

        printer.setFullPage(true);
        printer.setPageMargins(QMarginsF( 10.0,10.0,10.0,10.0), QPageLayout::Millimeter);
        QPainter painter(&printer);
        qreal left,top,right,bottom;

        auto margins = printer.pageLayout().margins();
        left = margins.left();
        right = margins.right();
        top = margins.top();
        bottom = margins.bottom();
        //printer.getPageMargins(&left,&top,&right,&bottom,QPrinter::DevicePixel);
        QRectF pageRect = printer.pageLayout().fullRectPixels(printer.resolution()) ;

        //qDebug() << "pageRect: " << pageRect;

        pageRect = pageRect.adjusted(left,top,-right,-bottom);

        //qDebug() << "pageRect: " << pageRect;
        //qDebug() << "sceneRect: " << sceneRect;

        scene->render(&painter,pageRect, sceneRect, Qt::IgnoreAspectRatio);

        //qDebug() << left << "," << right << "," << top << "," << bottom;
        //qDebug() << printer.paperRect().left() << ","
        //        << printer.paperRect().width() << ","
        //        << printer.paperRect().top() << ","
        //        << printer.paperRect().height();
        pageRect = printer.pageLayout().paintRectPixels(printer.resolution()) ;
        //qDebug() << pageRect.left() << ","
        //        << pageRect.width() << ","
        //        << pageRect.top() << ","
        //        << pageRect.height();

        QColor transparent(0,0,0,0);
        QColor transBorder (0,0,0,128);
        QPen pen (transBorder);
        pen.setStyle(Qt::DotLine);
        QBrush brush(transparent);

        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(pageRect);
        painter.end();
    }
}

