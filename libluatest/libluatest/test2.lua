-- *** DECLARATION PART ***
math.randomseed( os.time() )
seed = math.random(999999)

Module1=Perlin.new()
ModuleDesert=Perlin.new()
ModuleSea=Perlin.new()
TextureFlow_Module=RidgedMulti.new()
TurboDesert=Turbulence.new()
cylinderPole=Cylinders.new()
turboPoles=Turbulence.new()

HeightMapSea=NoiseMap.new()
TextureFlow_heightMap=NoiseMap.new()
heightMap=NoiseMap.new()
heightMapDesert=NoiseMap.new()
heightMapPole=NoiseMap.new()
TextureFlow_noiseMapBuilder1=NoiseMapBuilderSphere.new()
heightMapBuilderPole=NoiseMapBuilderSphere.new()
noiseMapBDesert=NoiseMapBuilderSphere.new()
noiseMapBuilder1=NoiseMapBuilderSphere.new()
noiseMapSea=NoiseMapBuilderSphere.new()

renderer1=RendererImage.new()
renderer2=RendererImage.new()
renderer3=RendererImage.new()
renderer4=RendererImage.new()
renderer5=RendererImage.new()
renderer0006=RendererImage.new()
renderer0007=RendererImage.new()
ImageSea=Image.new()
ImageSeaBmp=WriterBMP.new()

image1=Image.new()
image1Bmp=WriterBMP.new()

imageBump=Image.new()
imageBumpBmp=WriterBMP.new()

imageNormal=Image.new()
imageNormalBmp=WriterBMP.new()


-- *** INITIALIZATION PART ***

idx = 100

for i = -1.0,1.0,0.037 do

    idx = idx +1

    Module1.oct=6
    Module1.seed=seed
    Module1.freq=4.2 - i
    Module1.lac=2.2 + i
    Module1.pers=0.24


    ModuleDesert.oct=6
    ModuleDesert.seed=seed
    ModuleDesert.freq=4.5 - i
    ModuleDesert.lac=4.3 + i
    ModuleDesert.pers=0.35


    ModuleSea.oct=6
    ModuleSea.seed=seed
    ModuleSea.freq=1.8 - i
    ModuleSea.lac=5.3 + i
    ModuleSea.pers=0.23


    TextureFlow_Module.oct=6
    TextureFlow_Module.freq=6.6 - i
    TextureFlow_Module.lac=1.66912 + (i/20.0)


    TurboDesert.src1=ModuleDesert
    TurboDesert.seed=seed
    TurboDesert.freq=2.5
    TurboDesert.pow=0.55
    TurboDesert.rough=1.2

    cylinderPole.freq=0.5


    turboPoles.src1=cylinderPole
    turboPoles.seed=seed
    turboPoles.freq=4.5
    turboPoles.pow=0.2
    turboPoles.rough=3.2


    TextureFlow_noiseMapBuilder1:SetBounds(-90.0,90.0,-180.0,180.0)
    TextureFlow_noiseMapBuilder1:SetDestSize(1600,800)
    TextureFlow_noiseMapBuilder1:SetSourceModule(TextureFlow_Module)
    TextureFlow_noiseMapBuilder1:SetDestNoiseMap(TextureFlow_heightMap)
    TextureFlow_noiseMapBuilder1:Build()



    heightMapBuilderPole:SetBounds(-90.0,90.0,-180.0,180.0)
    heightMapBuilderPole:SetDestSize(1600,800)
    heightMapBuilderPole:SetSourceModule(turboPoles)
    heightMapBuilderPole:SetDestNoiseMap(heightMapPole)
    heightMapBuilderPole:Build()



    noiseMapBDesert:SetBounds(-90.0,90.0,-180.0,180.0)
    noiseMapBDesert:SetDestSize(1600,800)
    noiseMapBDesert:SetSourceModule(ModuleDesert)
    noiseMapBDesert:SetDestNoiseMap(heightMapDesert)
    noiseMapBDesert:Build()



    noiseMapBuilder1:SetBounds(-90.0,90.0,-180.0,180.0)
    noiseMapBuilder1:SetDestSize(1600,800)
    noiseMapBuilder1:SetSourceModule(Module1)
    noiseMapBuilder1:SetDestNoiseMap(heightMap)
    noiseMapBuilder1:Build()



    noiseMapSea:SetBounds(-90.0,90.0,-180.0,180.0)
    noiseMapSea:SetDestSize(1600,800)
    noiseMapSea:SetSourceModule(ModuleSea)
    noiseMapSea:SetDestNoiseMap(HeightMapSea)
    noiseMapSea:Build()



    renderer1:ClearGradient()
    renderer1:SetDestImage(image1)
    renderer1:SetSourceNoiseMap(heightMap)
    renderer1:SetBackgroundColor(Color.new(0,0,0,0))
    renderer1:AddGradientPoint(-1, Color.new(12,97,0,255))
    renderer1:AddGradientPoint(-0.0560472, Color.new(115,146,0,255))
    renderer1:AddGradientPoint(0.915663, Color.new(0,195,0,255))
    renderer1:AddGradientPoint(1, Color.new(255,255,255,255))
    renderer1:Render()


    renderer2:ClearGradient()
    renderer2:SetDestImage(image1)
    renderer2:SetSourceNoiseMap(heightMapDesert)
    renderer2:SetBackgroundColor(Color.new(0,0,0,0))
    renderer2:SetBackgroundImage(image1)
    renderer2:AddGradientPoint(-1, Color.new(251,247,244,0))
    renderer2:AddGradientPoint(-0.799197, Color.new(7,0,0,0))
    renderer2:AddGradientPoint(-0.0281124, Color.new(208,209,95,65))
    renderer2:AddGradientPoint(1, Color.new(232,212,117,135))
    renderer2:Render()


    renderer3:ClearGradient()
    renderer3:SetDestImage(ImageSea) --
    renderer3:SetSourceNoiseMap(HeightMapSea)
    renderer3:SetBackgroundColor(Color.new(0,0,0,0))
    renderer3:SetBackgroundImage(image1)
    renderer3:AddGradientPoint(-1, Color.new(0,31,174,255))
    renderer3:AddGradientPoint(-0.590361, Color.new(0,14,239,255))
    renderer3:AddGradientPoint(0.0240964, Color.new(0,80,235,255))
    renderer3:AddGradientPoint(0.168675, Color.new(85,226,234,255))
    renderer3:AddGradientPoint(0.183381, Color.new(109,185,114,255))
    renderer3:AddGradientPoint(0.253012, Color.new(120,166,59,255))
    renderer3:AddGradientPoint(0.337349, Color.new(214,176,146,0))
    renderer3:AddGradientPoint(0.506024, Color.new(127,207,251,0))
    renderer3:AddGradientPoint(0.903614, Color.new(129,167,59,255))
    renderer3:AddGradientPoint(0.939759, Color.new(117,225,251,255))
    renderer3:AddGradientPoint(1, Color.new(0,203,224,255))
    renderer3:Render()


    renderer4:ClearGradient()
    renderer4:SetDestImage(ImageSea)
    renderer4:SetSourceNoiseMap(heightMapPole)
    renderer4:SetBackgroundColor(Color.new(0,0,0,0))
    renderer4:SetBackgroundImage(ImageSea)
    renderer4:AddGradientPoint(-1, Color.new(0,0,0,0))
    renderer4:AddGradientPoint(0.329317, Color.new(254,251,248,0))
    renderer4:AddGradientPoint(0.373494, Color.new(255,253,251,255))
    renderer4:AddGradientPoint(1, Color.new(255,254,252,255))
    renderer4:Render()


    renderer5:ClearGradient()
    renderer5:SetDestImage(imageBump)
    renderer5:SetSourceNoiseMap(HeightMapSea)
    renderer5:SetBackgroundColor(Color.new(0,0,0,0))
    renderer5:AddGradientPoint(-1, Color.new(255,255,255,255))
    renderer5:AddGradientPoint(0.167, Color.new(255,255,255,255))
    renderer5:AddGradientPoint(0.168, Color.new(0,0,0,255))
    renderer5:AddGradientPoint(0.91, Color.new(0,0,0,255))
    renderer5:AddGradientPoint(0.911, Color.new(255,255,255,255))
    renderer5:AddGradientPoint(1, Color.new(255,255,255,255))
    renderer5:Render()


    renderer0006:ClearGradient()
    renderer0006:SetDestImage(imageNormal)
    renderer0006:SetSourceNoiseMap(TextureFlow_heightMap)
    renderer0006:SetBackgroundColor(Color.new(0,0,0,0))
    renderer0006:AddGradientPoint(0.012844, Color.new(0,0,0,255))
    renderer0006:AddGradientPoint(0.856, Color.new(255,255,255,255))
    renderer0006:AddGradientPoint(1, Color.new(255,255,255,255))
    renderer0006:Render()


    renderer0007:ClearGradient()
    renderer0007:SetDestImage(imageNormal)
    renderer0007:SetSourceNoiseMap(HeightMapSea)
    renderer0007:SetBackgroundColor(Color.new(0,0,0,0))
    renderer0007:SetBackgroundImage(imageNormal)
    renderer0007:AddGradientPoint(-1, Color.new(0,0,0,255))
    renderer0007:AddGradientPoint(0.255046, Color.new(0,0,0,255))
    renderer0007:AddGradientPoint(0.574312, Color.new(0,0,0,0))
    renderer0007:AddGradientPoint(0.84456, Color.new(0,0,0,0))
    renderer0007:AddGradientPoint(0.904, Color.new(255,255,255,0))
    renderer0007:AddGradientPoint(1, Color.new(255,255,255,255))
    renderer0007:Render()


    ImageSeaBmp.DestFilename ="./realisticSea" .. idx .. "-".. i .. ".png"
    ImageSeaBmp.SourceImage=ImageSea
    ImageSeaBmp:WritePngFile()



    image1Bmp.DestFilename ="./realistic" .. idx .. "-".. i .. ".png"
    image1Bmp.SourceImage=image1
    image1Bmp:WritePngFile()



    imageBumpBmp.DestFilename ="./realisticBump" .. idx .. "-".. i .. ".png"
    imageBumpBmp.SourceImage=imageBump
    imageBumpBmp:WritePngFile()



    imageNormalBmp.DestFilename ="./realisticNormal" .. idx .. "-".. i .. ".png"
    imageNormalBmp.SourceImage=imageNormal
    imageNormalBmp:WritePngFile()
    print ("Written images " .. idx)
end
print ("Done!")

