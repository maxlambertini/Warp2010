#include "rendererdescriptor.h"

RendererDescriptor::RendererDescriptor()
{

}

QSharedPointer<utils::RendererImage> RendererDescriptor::makeRenderer() {
    utils::RendererImage* p = new utils::RendererImage();
    p->EnableLight(this->_enabledLight);
    p->SetLightBrightness(this->lightBrightness());
    p->SetLightContrast(this->lightContrast());
    auto theMap = _noiseMaps[this->_noiseMap];
    p->SetSourceNoiseMap(*theMap.data());
    QSharedPointer<utils::RendererImage> sp; sp.reset(p);
    return sp;
}

void RendererDescriptor::toJson(QJsonObject& json) {
    json["name"] = _name;
    json["noiseMap"] = _noiseMap;
    json["enabledLight"] = _enabledLight;
    json["lightContrast"] = _lightContrast;
    json["lightBrightness"] = _lightBrightness;
}

void RendererDescriptor::fromJson(const QJsonObject& json) {
    if (!json["name"].isNull() && !json["name"].isUndefined())
        _name = json["name"].toString();
    if (!json["noiseMap"].isNull() && !json["noiseMap"].isUndefined())
        _noiseMap = json["noiseMap"].toString();
    if (!json["enabledLight"].isNull() && !json["enabledLight"].isUndefined())
        _enabledLight = json["enabledLight"].toBool();
    if (!json["lightContrast"].isNull() && !json["lightContrast"].isUndefined())
        _lightContrast = json["lightContrast"].toBool();
    if (!json["lightBrightness"].isNull() && !json["lightBrightness"].isUndefined())
        _lightBrightness = json["lightBrightness"].toBool();
    if (!json["gradientInfo"].isNull() && !json["gradientInfo"].isUndefined()) {
        QJsonArray gi = json["gradientInfo"].toArray();
        _gradientInfo.clear();
        for (auto h = 0; h < gi.size(); h++) {
            QJsonArray i = gi[h].toArray();
            auto grad = GradientInfo(i[0].toDouble(),
                    i[1].toInt(),i[2].toInt(),i[3].toInt(),i[4].toInt());
            _gradientInfo.append(grad);
        }
    }

}
