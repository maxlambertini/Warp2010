#include "libnoiselua.h"
#include <noise/module/module.h>
#include <noise/module/cos.h>

using namespace noise::module;
using namespace utils;

Libnoiselua::Libnoiselua()
{
    _lua.open_libraries();

    _lua.new_usertype<utils::NoiseMap>("NoiseMap",
                                      sol::constructors<utils::NoiseMap()>());

    _lua.new_usertype<utils::Image>("Image",
                                   sol::constructors<utils::Image()>());

    _lua.new_usertype<Abs>("Abs",
                             sol::constructors<Abs()>(),
                             "src1", sol::property(&Abs::GetSrc1, &Abs::SetSrc1)
                             );

    _lua.new_usertype<Add>("Add",
                             sol::constructors<Add()>(),
                             "src1", sol::property(&Add::GetSrc1, &Add::SetSrc1),
                             "src2", sol::property(&Add::GetSrc2, &Add::SetSrc2)
                             );

    _lua.new_usertype<Avg>("Avg",
                             sol::constructors<Avg()>(),
                             "src1", sol::property(&Avg::GetSrc1, &Avg::SetSrc1),
                             "src2", sol::property(&Avg::GetSrc2, &Avg::SetSrc2)
                             );

    _lua.new_usertype<Billow>("Billow",
                             sol::constructors<Billow()>(),
                             "freq", sol::property(&Billow::GetFrequency, &Billow::SetFrequency),
                             "lac", sol::property(&Billow::GetLacunarity, &Billow::SetLacunarity),
                             "octave", sol::property(&Billow::GetOctaveCount, &Billow::SetOctaveCount),
                             "pers", sol::property(&Billow::GetPersistence, &Billow::SetPersistence),
                             "seed", sol::property(&Billow::GetSeed, &Billow::SetSeed)
                             );

    _lua.new_usertype<Blend>("Blend",
                             sol::constructors<Blend()>(),
                             "src1", sol::property(&Blend::GetSrc1, &Blend::SetSrc1),
                             "src2", sol::property(&Blend::GetSrc2, &Blend::SetSrc2),
                             "ctl", sol::property(&Blend::GetCtl, &Blend::SetCtl)
                             );

    _lua.new_usertype<Clamp>("Clamp",
                             sol::constructors<Clamp()>(),
                             "src1", sol::property(&Clamp::GetSrc1, &Clamp::SetSrc1),
                             "ubound", sol::property(&Clamp::GetUpperBound, &Clamp::SetUpperBound),
                             "lbound", sol::property(&Clamp::GetLowerBound, &Clamp::SetLowerBound)
                             );

    _lua.new_usertype<Const>("Const",
                             sol::constructors<Const()>(),
                             "value", sol::property(&Const::GetConstValue, &Const::SetConstValue)
                             );

    _lua.new_usertype<Cos>("Cos",
                             sol::constructors<Cos()>(),
                             "src1", sol::property(&Cos::GetSrc1, &Cos::SetSrc1)
                             );

    _lua.new_usertype<Cylinders>("Cylinders",
                             sol::constructors<Cylinders>(),
                             "freq", sol::property(&Cylinders::GetFrequency, &Cylinders::SetFrequency)
                             );

    _lua.new_usertype<Displace>("Displace",
                             sol::constructors<Displace>(),
                             "src1", sol::property(&Displace::GetSrc1, &Displace::SetSrc1),
                             "src2", sol::property(&Displace::GetSrc2, &Displace::SetSrc2),
                             "src3", sol::property(&Displace::GetSrc3, &Displace::SetSrc3),
                             "src4", sol::property(&Displace::GetSrc4, &Displace::SetSrc4),
                             "ctl", sol::property(&Displace::GetCtl, &Displace::GetCtl)
                             );

    _lua.new_usertype<Exponent>("Exponent",
                             sol::constructors<Exponent()>(),
                             "src1", sol::property(&Exponent::GetSrc1, &Exponent::SetSrc1),
                             "exp",  sol::property(&Exponent::GetExponent, &Exponent::SetExponent)
                             );

    _lua.new_usertype<Invert>("Invert",
                             sol::constructors<Invert()>(),
                             "src1", sol::property(&Invert::GetSrc1, &Invert::SetSrc1)
                             );

    _lua.new_usertype<Max>("Add",
                             sol::constructors<Max()>(),
                             "src1", sol::property(&Max::GetSrc1, &Max::SetSrc1),
                             "src2", sol::property(&Max::GetSrc2, &Max::SetSrc2)
                             );

    _lua.new_usertype<Min>("Min",
                             sol::constructors<Min()>(),
                             "src1", sol::property(&Min::GetSrc1, &Min::SetSrc1),
                             "src2", sol::property(&Min::GetSrc2, &Min::SetSrc2)
                             );

    _lua.new_usertype<Multiply>("Multiply",
                             sol::constructors<Multiply()>(),
                             "src1", sol::property(&Multiply::GetSrc1, &Multiply::SetSrc1),
                             "src2", sol::property(&Multiply::GetSrc2, &Multiply::SetSrc2)
                             );


    _lua.new_usertype<Perlin>("Perlin",
                             sol::constructors<Perlin()>(),
                             "freq", sol::property(&Perlin::GetFrequency, &Perlin::SetFrequency),
                             "lac", sol::property(&Perlin::GetLacunarity, &Perlin::SetLacunarity),
                             "octave", sol::property(&Perlin::GetOctaveCount, &Perlin::SetOctaveCount),
                             "pers", sol::property(&Perlin::GetPersistence, &Perlin::SetPersistence),
                             "seed", sol::property(&Perlin::GetSeed, &Perlin::SetSeed)
                             );

    _lua.new_usertype<Power>("Power",
                             sol::constructors<Multiply()>(),
                             "src1", sol::property(&Power::GetSrc1, &Power::SetSrc1),
                             "src2", sol::property(&Power::GetSrc2, &Power::SetSrc2)
                             );

    _lua.new_usertype<RidgedMulti>("RidgedMulti",
                             sol::constructors<RidgedMulti()>(),
                             "freq", sol::property(&RidgedMulti::GetFrequency, &RidgedMulti::SetFrequency),
                             "lac", sol::property(&RidgedMulti::GetLacunarity, &RidgedMulti::SetLacunarity),
                             "octave", sol::property(&RidgedMulti::GetOctaveCount, &RidgedMulti::SetOctaveCount),
                             "seed", sol::property(&RidgedMulti::GetSeed, &RidgedMulti::SetSeed)
                             );

    _lua.new_usertype<RidgedMulti2>("RidgedMulti2",
                             sol::constructors<RidgedMulti()>(),
                             "freq", sol::property(&RidgedMulti2::GetFrequency, &RidgedMulti2::SetFrequency),
                             "lac", sol::property(&RidgedMulti2::GetLacunarity, &RidgedMulti2::SetLacunarity),
                             "gain", sol::property(&RidgedMulti2::GetGain, &RidgedMulti2::SetGain),
                             "offset", sol::property(&RidgedMulti2::GetOffset, &RidgedMulti2::SetOffset),
                             "weight", sol::property(&RidgedMulti2::GetWeight, &RidgedMulti2::SetWeight),
                             "exp", sol::property(&RidgedMulti2::GetExponent, &RidgedMulti2::SetExponent),
                             "octave", sol::property(&RidgedMulti2::GetOctaveCount, &RidgedMulti2::SetOctaveCount),
                             "seed", sol::property(&RidgedMulti2::GetSeed, &RidgedMulti2::SetSeed)
                             );

    _lua.new_usertype<Turbulence>("Turbulence",
                                  sol::constructors<Turbulence()>(),
                                  "freq", sol::property(&Turbulence::GetFrequency,&Turbulence::SetFrequency),
                                  "pow" , sol::property(&Turbulence::GetPower,&Turbulence::SetPower),
                                  "seed" , sol::property(&Turbulence::GetSeed,&Turbulence::SetSeed),
                                  "rough", sol::property(&Turbulence::SetRoughness),
                                  "src1",  sol::property(&Turbulence::GetSrc1,&Turbulence::SetSrc1));

    _lua.new_usertype<Turbulence2>("Turbulence2",
                                  sol::constructors<Turbulence2()>(),
                                  "freq", sol::property(&Turbulence2::GetFrequency,&Turbulence2::SetFrequency),
                                  "pow" , sol::property(&Turbulence2::GetPower,&Turbulence2::SetPower),
                                  "seed" , sol::property(&Turbulence2::GetSeed,&Turbulence2::SetSeed),
                                  "rough", sol::property(&Turbulence2::SetRoughness),
                                  "src1",  sol::property(&Turbulence2::GetSrc1,&Turbulence2::SetSrc1));

    _lua.new_usertype<TurbulenceBillow>("TurbulenceBillow",
                                  sol::constructors<TurbulenceBillow()>(),
                                  "freq", sol::property(&TurbulenceBillow::GetFrequency,&TurbulenceBillow::SetFrequency),
                                  "pow" , sol::property(&TurbulenceBillow::GetPower,&TurbulenceBillow::SetPower),
                                  "seed" , sol::property(&TurbulenceBillow::GetSeed,&TurbulenceBillow::SetSeed),
                                  "rough", sol::property(&TurbulenceBillow::SetRoughness),
                                  "src1",  sol::property(&TurbulenceBillow::GetSrc1,&TurbulenceBillow::SetSrc1));

    _lua.new_usertype<TurbulenceRidged>("TurbulenceRidged",
                                  sol::constructors<TurbulenceRidged()>(),
                                  "freq", sol::property(&TurbulenceRidged::GetFrequency,&TurbulenceRidged::SetFrequency),
                                  "pow" , sol::property(&TurbulenceRidged::GetPower,&TurbulenceRidged::SetPower),
                                  "seed" , sol::property(&TurbulenceRidged::GetSeed,&TurbulenceRidged::SetSeed),
                                  "rough", sol::property(&TurbulenceRidged::SetRoughness),
                                  "src1",  sol::property(&TurbulenceRidged::GetSrc1,&TurbulenceRidged::SetSrc1));

    _lua.new_usertype<Voronoi>("Voronoi",
                                  sol::constructors<Voronoi()>(),
                                  "freq",  sol::property(&Voronoi::GetFrequency,&Voronoi::SetFrequency),
                                  "seed" , sol::property(&Voronoi::GetSeed,&Voronoi::SetSeed),
                                  "displ", sol::property(&Voronoi::GetDisplacement, &Voronoi::SetDisplacement),
                                  "enableDist", sol::property(&Voronoi::GetEnableDistance, &Voronoi::EnableDistance));

    _lua.new_usertype<Color>("Color",
                            sol::constructors<Color(), Color(std::string), Color(uint8,uint8,uint8,uint8)>(),
                            "red", &Color::red, "green", &Color::green, "blue", &Color::blue, "alpha", &Color::alpha,
                            "darken", &Color::darken, "lighten", &Color::lighten,
                            "randomizeColor", &Color::randomizeColor
                            );

    _lua.new_usertype<utils::NoiseMapBuilderSphere>("NoiseMapBuilderSphere",
                             sol::constructors<NoiseMapBuilderSphere()>(),
                             "SetSourceModule", &NoiseMapBuilderSphere::SetSourceModule,
                             "Build",&NoiseMapBuilderSphere::Build,
                             "SetBounds",&NoiseMapBuilderSphere::SetBounds,
                             "SetDestSize",&NoiseMapBuilderSphere::SetDestSize,
                             "SetDestNoiseMap",&NoiseMapBuilderSphere::SetDestNoiseMap
                             );

    _lua.new_usertype<WriterBMP>("WriterBMP",
                                sol::constructors<WriterBMP()>(),
                                "DestFilename", sol::property(&WriterBMP::GetDestFilename,&WriterBMP::SetDestFilename),
                                "SourceImage", sol::property(&WriterBMP::GetSourceImage,&WriterBMP::SetSourceImage),
                                "WriteDestFile",&WriterBMP::WriteDestFile);

    _lua.new_usertype<RendererImage>("RendererImage",
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
