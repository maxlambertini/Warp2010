#include "libnoiselua.h"
#include <noise/module/module.h>

using namespace noise::module;

Libnoiselua::Libnoiselua()
{
    lua.open_libraries();
    /*
    lua.new_usertype<Figghiu>("Figghiu",
                                sol::constructors<Figghiu(), Figghiu(std::string)>(),
                                "patri", sol::property(&Figghiu::patri, &Figghiu::setPatri),
                                "nome" , sol::property(&Figghiu::nome, &Figghiu::setNome),
                            "interroga", &Figghiu::interroga,
                            "itera", &Figghiu::itera,
                            "scriviQuestaTupla", &Figghiu::scriviQuestaTupla,
                            "saluta",&Figghiu::saluta);
    */
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
}
