#include "libnoiselua.h"
#include <noise/module/module.h>

using namespace noise::module;
using namespace utils;

Libnoiselua::Libnoiselua()
{
    lua.open_libraries();

    lua.new_usertype<utils::NoiseMap>("NoiseMap",
                                      sol::constructors<utils::NoiseMap()>());

    lua.new_usertype<utils::Image>("Image",
                                   sol::constructors<utils::Image()>());

    lua.new_usertype<Perlin>("Perlin",
                             sol::constructors<Perlin()>(),
                             "freq", sol::property(&Perlin::GetFrequency, &Perlin::SetFrequency),
                             "lac", sol::property(&Perlin::GetLacunarity, &Perlin::SetLacunarity),
                             "octave", sol::property(&Perlin::GetOctaveCount, &Perlin::SetOctaveCount),
                             "pers", sol::property(&Perlin::GetPersistence, &Perlin::SetPersistence),
                             "seed", sol::property(&Perlin::GetSeed, &Perlin::SetSeed)
                             );

    lua.new_usertype<Color>("Color",
                            sol::constructors<Color(), Color(std::string), Color(uint8,uint8,uint8,uint8)>(),
                            "red", &Color::red, "green", &Color::green, "blue", &Color::blue, "alpha", &Color::alpha,
                            "darken", &Color::darken, "lighten", &Color::lighten,
                            "randomizeColor", &Color::randomizeColor
                            );

    lua.new_usertype<utils::NoiseMapBuilderSphere>("NoiseMapBuilderSphere",
                             sol::constructors<NoiseMapBuilderSphere()>(),
                             "SetSourceModule", &NoiseMapBuilderSphere::SetSourceModule,
                             "Build",&NoiseMapBuilderSphere::Build,
                             "SetBounds",&NoiseMapBuilderSphere::SetBounds,
                             "SetDestSize",&NoiseMapBuilderSphere::SetDestSize,
                             "SetDestNoiseMap",&NoiseMapBuilderSphere::SetDestNoiseMap
                             );

    lua.new_usertype<WriterBMP>("WriterBMP",
                                sol::constructors<WriterBMP()>(),
                                "DestFilename", sol::property(&WriterBMP::GetDestFilename,&WriterBMP::SetDestFilename),
                                "SourceImage", sol::property(&WriterBMP::GetSourceImage,&WriterBMP::SetSourceImage),
                                "WriteDestFile",&WriterBMP::WriteDestFile);

    lua.new_usertype<RendererImage>("RendererImage",
                                    sol::constructors<RendererImage()>(),
                                    "SetSourceNoiseMap",&RendererImage::SetSourceNoiseMap,
                                    "SetDestImage",&RendererImage::SetDestImage,
                                    "SetBackgroundImage",&RendererImage::SetBackgroundImage,
                                    "SetBackgroundColor",&RendererImage::SetBackgroundColor,
                                    "SetBumpNoiseMap", &RendererImage::SetBumpNoiseMap,
                                    "SetAlphaImage",&RendererImage::SetAlphaImage,
                                    "ClearGradient",&RendererImage::ClearGradient,
                                    "AddGradientPoint", &RendererImage::AddGradientPoint,
                                    "EnableLight", &RendererImage::EnableLight,
                                    "SetLightContrast", &RendererImage::SetLightContrast,
                                    "SetLightBrightness", &RendererImage::SetLightBrightness,
                                    "Render", &RendererImage::Render);
}
