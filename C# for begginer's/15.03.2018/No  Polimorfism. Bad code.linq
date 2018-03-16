<Query Kind="Program" />

void Main()
{
	Shape[] shapes = new Shape[]
		{ new Square(), new Triangle(), new Circle(), new Square(), new Triangle(), new Circle()};
	
	for (int i = 0; i < shapes.Length; i++)
	{
		ClientCode1(shapes[i]);
	}
	"=====".Dump();
	for (int i = 0; i < shapes.Length; i++)
	{
		ClientCode(shapes[i]);
	}

}

public class Shape
{
	public void Draw() => "Shape".Dump();
}

public class Circle : Shape
{
	public new void Draw() => "Circle".Dump();
}

public class Square : Shape
{
	public new void Draw() => "Square".Dump();
}

public class Triangle : Shape
{
	public new void Draw() => "Triangle".Dump();
}

public static void ClientCode1(Shape shape)
{
	shape.Draw();
}

public static void ClientCode(Shape shape)
{
	if (shape.GetType() == typeof(Circle))
	{
		((Circle)shape).Draw();
	}
	else if (shape.GetType() == typeof(Square))
	{
		((Square)shape).Draw();
	}
	else if (shape.GetType() == typeof(Triangle))
	{
		((Triangle)shape).Draw();
	}
}