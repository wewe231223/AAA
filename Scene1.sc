# Mesh -> read mesh ( mesh file name / mesh name )
# Model -> add single model ( mesh name / pos.x / pos.y / pos.z / rot.x / rot.y / rot.z / scale / fill / cull )
# x -> Coord Reder Mode ( a == Render line and XZ , l = Render Line only , s = Render side only)
Coord l

Mesh sphere.obj sphere
Mesh teapot.obj teapot



Model sphere 0 0 0 0 0 0 1 t t
<Component> Circle 0 0 0 70.71 0 1 0 0
<Component> Circle 0 0 0 70.71 1 0 1 90
<Component> Circle 0 0 0 70.71 -1 0 1 90
{

Model sphere 50 0 -50 0 0 0 0.3 t t
<Component> Circle 0 0 0 40 0 1 0 0
<Animation> Revolution 5 1 0 1

{
	Model sphere 40 0 0 0 0 0 0.5 t t
	<Animation> Revolution 5 0 1 0
}


Model sphere -50 0 -50 0 0 0 0.3 t t
<Component> Circle 0 0 0 40 0 1 0 0
<Animation> Revolution 5 1 0 -1
{
	Model sphere 40 0 0 0 0 0 0.5 t t 
	<Animation> Revolution 5 0 1 0
}


Model sphere 50 0 50 0 0 0 0.3 t t
<Component> Circle 0 0 0 40 0 1 0 0
<Animation> Revolution 5 0 1 0
{
	Model sphere 40 0 0 0 0 0 0.5 t t 
	<Animation> Revolution 5 0 1 0
}


}
EndFile