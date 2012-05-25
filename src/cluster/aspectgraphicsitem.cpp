#include "aspectgraphicsitem.h"
#include "dialogs/preferencesdialog.h"
#include "helpers/preferences.h"

AspectGraphicsItem::AspectGraphicsItem()
{
}

AspectGraphicsItem::AspectGraphicsItem(float x, float y, float fLettersInWords, ClusterItem &item) :
        _clusterItem(item),_x(x),_y(y),_fLettersInWords(fLettersInWords)
{
    _aspectText = "";
    Aspect aspect;

    QFont fontBold = Preferences::prefs().fontAspectTitle();
    QFont font = Preferences::prefs().fontBody();
    QFontMetricsF metrics(font);
    QFontMetricsF metricsBold(fontBold);

    float fHeight = metricsBold.height() * 2.5;
    float fWidth = metricsBold.width(item.name());


    for (int i = 0; i < item.aspects().count(); i++)
    {
        aspect = item.aspects()[i];
        QStringList words = aspect.name().split(" ",QString::SkipEmptyParts);
        QString word;
        QString tempText = "";
        foreach (word, words) {
            if (tempText.length()+ word.length() <= (int)fLettersInWords)
                tempText += word+ " ";
            else {
                fWidth = metrics.width(tempText) > fWidth  ? metrics.width(tempText) : fWidth;
                fHeight += metrics.height()*1.1;
                _aspectText += tempText + " ";
                tempText = word+" ";
            }
        }
        fWidth = metrics.width(tempText) > fWidth  ? metrics.width(tempText) : fWidth;
        fHeight += metrics.height()*1.2;
        _aspectText += tempText+"\n";
    }

    QRectF metricsRect(_x,_y,fWidth, fHeight);
    _boundingRect = metricsRect.adjusted(-5,-5,+15,+5);
}

void AspectGraphicsItem::calcBoundingRect()
{

}

QRectF AspectGraphicsItem::boundingRect() const
{
    return _boundingRect;
}

void AspectGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QFont font = Preferences::prefs().fontBody();
    font.setWeight(1);
    QFont fontBold = Preferences::prefs().fontAspectTitle();
    fontBold.setWeight(99);
    QColor cyan = Preferences::prefs().colorDiasporaAspectBackground();
    QColor black = Preferences::prefs().colorDiasporaAspectBox();
    QBrush bCyan(cyan);
    QBrush bBlack(black);

    QRectF rect = this->boundingRect();
    QRectF rectText = rect.adjusted(5,5,-5,-5);

    QFontMetrics metricsBold(fontBold);

    float fHeight = metricsBold.height();
    float fWidth = metricsBold.width(_clusterItem.name());

    painter->setBrush(bCyan);
    painter->drawRoundRect(rect,5,5);
    painter->setBrush(bBlack);

    painter->setFont(fontBold);
    painter->drawText(QPointF(rectText.left(), rectText.top()+fHeight),_clusterItem.name());

    rectText = rectText.adjusted(0,fHeight*1.4,0,0);
    painter->setFont(font);

    painter->drawText(rectText,_aspectText);

}

void AspectGraphicsItem::recalcBoundingRect() {
    QRectF tmpRect = _boundingRect;
    float x = tmpRect.x();
    float y = tmpRect.y();
    float w = tmpRect.width();
    float h = tmpRect.height();
    switch(_alignment) {
    case AGIAlign::ALTopLeft:
        break;
    case AGIAlign::ALTopCenter:
        x -= w /2;
        break;
    case AGIAlign::ALTopRight:
        x -= w;
        break;
    case AGIAlign::ALCenterLeft:
        y -= h /2;
        break;
    case AGIAlign::ALCenter:
        y -= h/2;
        x -= w/2;
        break;
    case AGIAlign::ALCenterRight:
        y -= h/2;
        x -= w;
        break;
    case AGIAlign::ALBottomLeft:
        y -= h;
        break;
    case AGIAlign::ALBottomCenter:
        y -= h;
        x -= w/2;
        break;
    case AGIAlign::ALBottomRight:
        y -= h;
        x -= w;
        break;
    default:
        break;
    };
    _boundingRect.setX(x);
    _boundingRect.setY(y);
    _boundingRect.setWidth(w);
    _boundingRect.setHeight(h);
}
