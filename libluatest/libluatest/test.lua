print ("Hello, Warp!")

img    = Image.new()
hm     = NoiseMap.new()
hm2    = NoiseMap.new()

print ("Perlin....")
perlin = Perlin.new()

print ("rmf....")
rmf = RidgedMulti.new()

perlin.freq = 1.0 + math.random()*1.5
perlin.octave = 8
perlin.lac = 1.5+ 4.5*math.random()
perlin.pers = 0.2 + 0.35*math.random()
perlin.seed = math.random(0,99999)

rmf.freq = 1.0 + math.random()*1.5
rmf.octave = 8
rmf.lac = 1.5+ 4.5*math.random()
rmf.seed = math.random(0,99999)

print ("Turbo")

turbo = Turbulence.new()
turbo.freq = 1.5 * 5.0*math.random()
turbo.pow = 0.05 + 0.3*math.random()
turbo.seed = math.random(0,99999)
turbo.rough = 1.0 + math.random()*2.0
turbo.src1 = perlin


print ("Sphere")
hmb    = NoiseMapBuilderSphere.new()
hmb:SetBounds (-90.0, 90.0, -180.0, 180.0);
hmb:SetDestSize (2048, 1024);
hmb:SetSourceModule (turbo);
hmb:SetDestNoiseMap (hm);
hmb:Build ();

hmb2    = NoiseMapBuilderSphere.new()
hmb2:SetBounds (-90.0, 90.0, -180.0, 180.0);
hmb2:SetDestSize (2048, 1024);
hmb2:SetSourceModule (rmf);
hmb2:SetDestNoiseMap (hm2);
hmb2:Build ();


print ("Renderer")
rnd    = RendererImage.new()
rnd2   = RendererImage.new()

print ("Renderer")
rnd:ClearGradient ()
rnd:AddGradientPoint (-1.00, Color.new(  0,  0,128,255))
rnd:AddGradientPoint (-0.50, Color.new(  0,  0,255,255))
rnd:AddGradientPoint ( 0.00, Color.new(  0,  0,255,255))
rnd:AddGradientPoint ( 0.1, Color.new(  0,128,  0,255))
rnd:AddGradientPoint ( 0.80, Color.new(255,255,  0,255))
rnd:AddGradientPoint ( 1.00, Color.new(255,255,255,255))
rnd:SetSourceNoiseMap (hm);
rnd:SetDestImage (img);
rnd:Render()

rnd2:ClearGradient ()
rnd2:AddGradientPoint (-1.00, Color.new(128,  0,  0,255))
rnd2:AddGradientPoint (-0.80, Color.new(  0,  0,128,  0))
rnd2:AddGradientPoint (-0.50, Color.new(  0,  0,255,  0))
rnd2:AddGradientPoint ( 0.00, Color.new(  0,  0,255,  0))
rnd2:AddGradientPoint ( 0.1, Color.new(   0,128,  0,  0))
rnd2:AddGradientPoint ( 0.80, Color.new(255,255,  0,255))
rnd2:AddGradientPoint ( 1.00, Color.new(255,  0,255,255))
rnd2:SetSourceNoiseMap (hm2);
rnd2:SetBackgroundImage (img);
rnd2:SetDestImage (img);
rnd2:Render()


bmp    = WriterBMP.new()
bmp.DestFilename = "/home/maxl/pippo.bmp"
bmp.SourceImage = img
bmp:WriteDestFile()


print ("Objects created...")
