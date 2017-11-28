-- *** DECLARATION PART ***

Ridged2=Perlin.new()

RidgedMap=NoiseMap.new()

Ridged2Map=NoiseMapBuilderSphere.new()

BeginLayer_renderer=RendererImage.new()
BaseImage=Image.new()
BaseImageBmp=WriterBMP.new()


-- *** INITIALIZATION PART ***

w = 100
for i = -1,1,0.077 do
    w = w +1;

    print (w)

    Ridged2.oct=12
    Ridged2.seed=0
    Ridged2.freq=2.2+i
    Ridged2.lac=4.0+i*3.0
    Ridged2.pers=0.20-i/10.0


    Ridged2Map:SetBounds(-90.0,90.0,-180.0,180.0)
    Ridged2Map:SetDestSize(1024,512)
    Ridged2Map:SetSourceModule(Ridged2)
    Ridged2Map:SetDestNoiseMap(RidgedMap)
    Ridged2Map:Build()



    BeginLayer_renderer:ClearGradient()
    BeginLayer_renderer:SetDestImage(BaseImage)
    BeginLayer_renderer:SetSourceNoiseMap(RidgedMap)
    BeginLayer_renderer:SetBackgroundColor(Color.new(0,0,0,0))
    BeginLayer_renderer:AddGradientPoint(-1, Color.new(22,66,169,255))
    BeginLayer_renderer:AddGradientPoint(-0.0526316, Color.new(62,102,196,255))
    BeginLayer_renderer:AddGradientPoint(0.046252, Color.new(62,102,196,255))
    BeginLayer_renderer:AddGradientPoint(0.0909091, Color.new(235,228,171,255))
    BeginLayer_renderer:AddGradientPoint(0.253589, Color.new(235,206,114,255))
    BeginLayer_renderer:AddGradientPoint(0.496013, Color.new(92,181,59,255))
    BeginLayer_renderer:AddGradientPoint(0.945774, Color.new(158,131,52,255))
    BeginLayer_renderer:AddGradientPoint(1, Color.new(255,255,255,255))
    BeginLayer_renderer:Render()


    BaseImageBmp.DestFilename ="./imgBaseImage." .. w .. "_" .. i .. ".png"
    BaseImageBmp.SourceImage=BaseImage
    BaseImageBmp:WritePngFile()
end

