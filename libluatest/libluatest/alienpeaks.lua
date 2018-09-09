-- *** DECLARATION PART ***
math.randomseed( os.time() )
seed = math.random(999999)


basePerlin=Perlin.new()
blendModule=Blend.new()
expBase=Exponent.new()
rot=RotatePoint.new()
scaleBase=ScaleBias.new()
turbVoronoi=Turbulence.new()
voronoi=Voronoi.new()
heightMap=NoiseMap.new()
noiseMapBuilder1=NoiseMapBuilderSphere.new()
renderer0001=RendererImage.new()
image1=Image.new()
image1Bmp=WriterBMP.new()


-- *** INITIALIZATION PART ***

for d=-1,1,0.1 do
    basePerlin.oct=6
    basePerlin.seed=seed
    basePerlin.freq=2.5+d
    basePerlin.lac=3.2
    basePerlin.pers=0.3


    blendModule.src1=turbVoronoi
    blendModule.src2=rot
    blendModule.ctl=scaleBase


    expBase.src1=rot
    expBase.exp=4


    rot.src1=basePerlin
    rot.x=45
    rot.y=45
    rot.z=45


    scaleBase.src1=rot
    scaleBase.bias=0
    scaleBase.scale=0.7


    turbVoronoi.src1=voronoi
    turbVoronoi.seed=seed
    turbVoronoi.freq=2.5
    turbVoronoi.pow=0.18+d/10.0
    turbVoronoi.rough=5


    voronoi.seed=seed
    voronoi.freq=5+d*2.0
    voronoi.displ=0
    voronoi.enableDist=true


    noiseMapBuilder1:SetBounds(-90.0,90.0,-180.0,180.0)
    noiseMapBuilder1:SetDestSize(1280,640)
    noiseMapBuilder1:SetSourceModule(blendModule)
    noiseMapBuilder1:SetDestNoiseMap(heightMap)
    noiseMapBuilder1:Build()



    renderer0001:ClearGradient()
    renderer0001:SetDestImage(image1)
    renderer0001:SetSourceNoiseMap(heightMap)
    renderer0001:SetBackgroundColor(Color.new(0,0,0,0))
    renderer0001:EnableLight(true)
    renderer0001:SetLightContrast(1.2)
    renderer0001:SetLightBrightness(2)
    renderer0001:AddGradientPoint(-1, Color.new(137,134,161,255))
    renderer0001:AddGradientPoint(-0.487525, Color.new(212,222,155,255))
    renderer0001:AddGradientPoint(0.027225, Color.new(141,160,235,255))
    renderer0001:AddGradientPoint(0.646875, Color.new(214,234,237,255))
    renderer0001:AddGradientPoint(1, Color.new(160,226,62,255))
    renderer0001:Render()


    image1Bmp.DestFilename ="./alienPeaks-".. ( d * 100.0)  .. ".png"
    image1Bmp.SourceImage=image1
    image1Bmp:WritePngFile()
end

