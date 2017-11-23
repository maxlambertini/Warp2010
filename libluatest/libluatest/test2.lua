-- *** DECLARATION PART ***

BeginLayer_Module=RidgedMulti.new()

EndLayer_Module=Billow.new()

BeginLayer_heightMap=NoiseMap.new()

EndLayer_heightMap=NoiseMap.new()

BeginLayer_noiseMapBuilder1=NoiseMapBuilderSphere.new()

EndLayer_noiseMapBuilder1=NoiseMapBuilderSphere.new()

BeginLayer_renderer=RendererImage.new()
EndLayer_renderer=RendererImage.new()
BaseImage=Image.new()
BaseImageBmp=WriterBMP.new()


-- *** INITIALIZATION PART ***

BeginLayer_Module.oct=6
BeginLayer_Module.freq=1.416
BeginLayer_Module.lac=1.42688


EndLayer_Module.oct=6
EndLayer_Module.seed=0
EndLayer_Module.freq=1.82225
EndLayer_Module.lac=2.22733
EndLayer_Module.pers=0.25685


BeginLayer_noiseMapBuilder1:SetBounds(-90.0,90.0,-180.0,180.0)
BeginLayer_noiseMapBuilder1:SetDestSize(1024,512)
BeginLayer_noiseMapBuilder1:SetSourceModule(BeginLayer_Module)
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
BeginLayer_renderer:SetBackgroundColor(Color.new(0,0,0,0))
BeginLayer_renderer:AddGradientPoint(-1, Color.new(101,126,118,255))
BeginLayer_renderer:AddGradientPoint(-0.713914, Color.new(211,255,233,255))
BeginLayer_renderer:AddGradientPoint(-0.46769, Color.new(204,223,212,255))
BeginLayer_renderer:AddGradientPoint(-0.197469, Color.new(18,251,85,255))
BeginLayer_renderer:AddGradientPoint(0.0539746, Color.new(0,32,45,255))
BeginLayer_renderer:AddGradientPoint(0.0639746, Color.new(238,249,255,255))
BeginLayer_renderer:AddGradientPoint(0.344047, Color.new(22,130,246,255))
BeginLayer_renderer:AddGradientPoint(0.590379, Color.new(32,60,213,255))
BeginLayer_renderer:AddGradientPoint(0.810334, Color.new(73,96,201,255))
BeginLayer_renderer:AddGradientPoint(1, Color.new(108,74,205,255))
BeginLayer_renderer:Render()


EndLayer_renderer:ClearGradient()
EndLayer_renderer:SetDestImage(BaseImage)
EndLayer_renderer:SetSourceNoiseMap(EndLayer_heightMap)
EndLayer_renderer:SetBackgroundColor(Color.new(0,0,0,0))
EndLayer_renderer:SetBackgroundImage(BaseImage)
EndLayer_renderer:EnableLight()
EndLayer_renderer:SetLightContrast(1.4)
EndLayer_renderer:SetLightBrightness(2)
EndLayer_renderer:AddGradientPoint(-1, Color.new(205,255,202,255))
EndLayer_renderer:AddGradientPoint(-0.833333, Color.new(220,255,217,255))
EndLayer_renderer:AddGradientPoint(-0.666667, Color.new(252,253,252,255))
EndLayer_renderer:AddGradientPoint(-0.5, Color.new(168,172,169,255))
EndLayer_renderer:AddGradientPoint(-0.333333, Color.new(175,181,176,255))
EndLayer_renderer:AddGradientPoint(-0.166667, Color.new(178,186,180,255))
EndLayer_renderer:AddGradientPoint(-1.66533e-16, Color.new(199,203,200,0))
EndLayer_renderer:AddGradientPoint(0.166667, Color.new(205,208,205,0))
EndLayer_renderer:AddGradientPoint(0.333333, Color.new(206,211,207,0))
EndLayer_renderer:AddGradientPoint(0.5, Color.new(221,226,223,0))
EndLayer_renderer:AddGradientPoint(0.666667, Color.new(230,233,231,0))
EndLayer_renderer:AddGradientPoint(0.833333, Color.new(229,233,231,0))
EndLayer_renderer:AddGradientPoint(1, Color.new(233,234,162,0))
EndLayer_renderer:Render()

BaseImageBmp.DestFilename ="c:/tmp/imgImageSea777.bmp"
BaseImageBmp:WriteDestFile()
BaseImageBmp.DestFilename ="c:/tmp/imgImageSea777.png"
BaseImageBmp:WritePngFile()

