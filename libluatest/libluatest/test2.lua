-- *** DECLARATION PART ***

BeginLayer_Module=RidgedMulti.new()

Cos_Module_20=Sin.new()

EndLayer_Module=Billow.new()

Invert_Module_40=Invert.new()

Turbulence2_Module_30=Turbulence2.new()

BeginLayer_heightMap=NoiseMap.new()

EndLayer_heightMap=NoiseMap.new()

BeginLayer_noiseMapBuilder1=NoiseMapBuilderSphere.new()

EndLayer_noiseMapBuilder1=NoiseMapBuilderSphere.new()

BeginLayer_renderer=RendererImage.new()
renderer0002=RendererImage.new()
BaseBump=Image.new()
BaseBumpBmp=WriterBMP.new()

BaseImage=Image.new()
BaseImageBmp=WriterBMP.new()


-- *** INITIALIZATION PART ***

BeginLayer_Module.oct=9
BeginLayer_Module.freq=2.193
BeginLayer_Module.lac=6.34


Cos_Module_20.src1=BeginLayer_Module
Cos_Module_20.freq=0.314
Cos_Module_20.exp=0.4
Cos_Module_20.value=0.2


EndLayer_Module.oct=6
EndLayer_Module.seed=0
EndLayer_Module.freq=1.82225
EndLayer_Module.lac=2.22733
EndLayer_Module.pers=0.25685


Invert_Module_40.src1=Turbulence2_Module_30


Turbulence2_Module_30.src1=Cos_Module_20
Turbulence2_Module_30.seed=0
Turbulence2_Module_30.freq=4.5
Turbulence2_Module_30.pow=0.125
Turbulence2_Module_30.rough=2.125


BeginLayer_noiseMapBuilder1:SetBounds(-90.0,90.0,-180.0,180.0)
BeginLayer_noiseMapBuilder1:SetDestSize(1024,512)
BeginLayer_noiseMapBuilder1:SetSourceModule(Invert_Module_40)
BeginLayer_noiseMapBuilder1:SetDestNoiseMap(BeginLayer_heightMap)
BeginLayer_noiseMapBuilder1:Build()



EndLayer_noiseMapBuilder1:SetBounds(-90.0,90.0,-180.0,180.0)
EndLayer_noiseMapBuilder1:SetDestSize(1024,512)
EndLayer_noiseMapBuilder1:SetSourceModule(EndLayer_Module)
EndLayer_noiseMapBuilder1:SetDestNoiseMap(EndLayer_heightMap)
EndLayer_noiseMapBuilder1:Build()



BeginLayer_renderer:ClearGradient()
BeginLayer_renderer:SetDestImage(BaseImage)
BeginLayer_renderer:SetSourceNoiseMap(BeginLayer_heightMap)
BeginLayer_renderer:AddGradientPoint(-1, Color.new(132,86,68,255))
BeginLayer_renderer:AddGradientPoint(-0.883125, Color.new(157,115,89,255))
BeginLayer_renderer:AddGradientPoint(-0.55995, Color.new(145,114,92,255))
BeginLayer_renderer:AddGradientPoint(-0.26355, Color.new(129,84,74,255))
BeginLayer_renderer:AddGradientPoint(-0.104725, Color.new(139,106,84,255))
BeginLayer_renderer:AddGradientPoint(0.1694, Color.new(167,138,112,255))
BeginLayer_renderer:AddGradientPoint(0.386475, Color.new(193,162,137,255))
BeginLayer_renderer:AddGradientPoint(0.702075, Color.new(213,180,162,255))
BeginLayer_renderer:AddGradientPoint(0.87385, Color.new(234,201,186,255))
BeginLayer_renderer:AddGradientPoint(1, Color.new(229,192,182,255))
BeginLayer_renderer:Render()


renderer0002:ClearGradient()
renderer0002:SetDestImage(BaseBump)
renderer0002:SetSourceNoiseMap(BeginLayer_heightMap)
renderer0002:AddGradientPoint(-1, Color.new(0,0,0,255))
renderer0002:AddGradientPoint(1, Color.new(255,255,255,255))
renderer0002:Render()


BaseBumpBmp.DestFilename ="/home/maxl/imgBaseBump.bmp"
BaseBumpBmp.SourceImage=BaseBump
BaseBumpBmp:WriteDestFile()



BaseImageBmp.DestFilename ="/home/maxl/imgBaseImage.bmp"
BaseImageBmp.SourceImage=BaseImage
BaseImageBmp:WriteDestFile()


