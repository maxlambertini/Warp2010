print ("Hello, Warp!")

img    = Image.new()
hm     = NoiseMap.new()
hm2    = NoiseMap.new()

print ("Perlin....")
perlin = Perlin.new()

print ("rmf....")
rmf = RidgedMulti.new()

print ("voro....")
voro = Voronoi.new()

perlin.freq = 1.0 + math.random()*1.5
perlin.octave = 8
perlin.lac = 1.5+ 4.5*math.random()
perlin.pers = 0.2 + 0.35*math.random()
perlin.seed = math.random(0,99999)

rmf.freq = 1.0 + math.random()*1.5
rmf.octave = 8
rmf.lac = 1.5+ 4.5*math.random()
rmf.seed = math.random(0,99999)

voro.freq = 1.0 + math.random()*1.5
voro.enableDist = true
voro.displ = 0.0
voro.seed = math.random(0,99999)

print ("Turbo")

turbo = Turbulence2.new()
turbo.freq = 1.5 * 5.0*math.random()
turbo.pow = 0.05 + 0.3*math.random()
turbo.seed = math.random(0,99999)
turbo.rough = 1.0 + math.random()*2.0
turbo.src1 = perlin

_abs = Abs.new()
_abs.src1 = voro

blend = Blend.new()
blend.src1 = turbo
blend.src2 = _abs
blend.ctl = rmf


print ("Sphere")
hmb    = NoiseMapBuilderSphere.new()
hmb:SetBounds (-90.0, 90.0, -180.0, 180.0);
hmb:SetDestSize (2048, 1024);
hmb:SetSourceModule (blend);
hmb:SetDestNoiseMap (hm);
hmb:Build ();



print ("Renderer")
rnd    = RendererImage.new()

print ("Renderer")
rnd:ClearGradient ()
rnd:AddGradientPoint (-1.00, Color.new(  0,  0,128,255))
rnd:AddGradientPoint ( 0.10, Color.new(  0,  0,255,255))
rnd:AddGradientPoint ( 0.30, Color.new(  0,  0,255,255))
rnd:AddGradientPoint ( 0.32, Color.new(  0,128,  0,255))
rnd:AddGradientPoint ( 0.77, Color.new(255,192,128,255))
rnd:AddGradientPoint ( 0.97, Color.new(255,255,  0,255))
rnd:AddGradientPoint ( 1.00, Color.new(255,255,255,255))
rnd:SetSourceNoiseMap (hm);
rnd:SetDestImage (img);
rnd:Render()


bmp    = WriterBMP.new()
bmp.DestFilename = "/home/maxl/pippo.bmp"
bmp.SourceImage = img
bmp:WriteDestFile()
bmp.DestFilename = "/home/maxl/pippo.png"
bmp:WritePngFile()


print ("Objects created...")
