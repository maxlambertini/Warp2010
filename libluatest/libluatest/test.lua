print ("Hello, Warp!")

img    = Image.new()
hm     = NoiseMap.new()

print ("Perlin....")
perlin = Perlin.new()

perlin.freq = 1.0 + math.random()*1.5
perlin.octave = 8
perlin.lac = 1.5+ 4.5*math.random()
perlin.pers = 0.2 + 0.35*math.random()
perlin.seed = math.random(0,99999)

print ("Turbo")

turbo = Turbulence.new()
print ("Turbo")
turbo.freq = 1.5 * 5.0*math.random()
print ("Turbo")
turbo.pow = 0.05 + 0.3*math.random()
print ("Turbo")
turbo.seed = math.random(0,99999)
print ("Turbo")
turbo:SetRoughness(1.0 + math.random()*2.0)
print ("Turbo")
turbo:SetSourceModule(0,perlin)
print ("Turbo")


print ("Sphere")
hmb    = NoiseMapBuilderSphere.new()
print ("Sphere")

hmb:SetBounds (-90.0, 90.0, -180.0, 180.0);
print ("Sphere")
hmb:SetDestSize (2048, 1024);

print ("Sphere")
hmb:SetSourceModule (turbo);
print ("Sphere")
hmb:SetDestNoiseMap (hm);
print ("Sphere")
hmb:Build ();
print ("Sphere")


print ("Renderer")
rnd    = RendererImage.new()

print ("Renderer")
rnd:ClearGradient ()
print ("Renderer")
rnd:AddGradientPoint (-1.00, Color.new(  0,  0,128,255))
print ("Renderer")
rnd:AddGradientPoint (-0.50, Color.new(  0,  0,255,255))
print ("Renderer")
rnd:AddGradientPoint ( 0.00, Color.new(  0,  0,255,255))
print ("Renderer")
rnd:AddGradientPoint ( 0.1, Color.new(  0,128,  0,255))
print ("Renderer")
rnd:AddGradientPoint ( 0.80, Color.new(255,255,  0,255))
print ("Renderer")
rnd:AddGradientPoint ( 1.00, Color.new(255,255,255,255))
print ("Renderer")

rnd:SetSourceNoiseMap (hm);
rnd:SetDestImage (img);
rnd:Render()

bmp    = WriterBMP.new()
bmp.DestFilename = "/home/maxl/pippo.bmp"
bmp.SourceImage = img
bmp:WriteDestFile()


print ("Objects created...")
