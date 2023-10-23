
# Mesh -> read mesh ( mesh file name / mesh name )
# Model -> add single model ( mesh name / pos.x / pos.y / pos.z / rot.x / rot.y / rot.z / scale / fill / cull )
# x -> Coord Reder Mode ( a == Render line and XZ , l = Render Line only , s = Render side only)
Coord a

Mesh sphere.obj sphere
Mesh teapot.obj teapot

Model	sphere 10	100	10	0 0 0 1		t t
{
	Model	sphere 10	0	10	0 0 0 2		t t

	{
		Model	sphere 20	0	0	0 0 0 1		t t
		Model	sphere 40	0	0	0 0 0 1		t t
		Model	sphere 60	0	0	0 0 0 1		t t
		Model	sphere 80	0	0	0 0 0 1		t t
	}

	Model teapot 20 0 0 0 0 0 2 t t
}


Model teapot 100 100 -100 0 0 0 7 t t
{
	Model sphere 20 0 0 0 0 0 1 t t
}


EndFile