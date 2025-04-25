'''7. Create a class for representing any 2-D point or vector. The methods inside this class include 
its magnitude and its rotation with respect to the X-axis. Using the objects define functions for 
calculating the distance between two vectors, dot product, cross product of two vectors. Extend 
the 2-D vectors into 3-D using the concept of inheritance. Update the methods according to 3-
D.'''

import math

class Point2D:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2)

    def rotation(self):
        return math.degrees(math.atan2(self.y, self.x))

    @staticmethod
    def distance(p1, p2):
        return math.sqrt((p2.x - p1.x) ** 2 + (p2.y - p1.y) ** 2)

    @staticmethod
    def dot_product(p1, p2):
        return p1.x * p2.x + p1.y * p2.y

    @staticmethod
    def cross_product(p1, p2):
        return p1.x * p2.y - p1.y * p2.x

    def __repr__(self):
        return f"({self.x}, {self.y})"

class Point3D(Point2D):
    def __init__(self, x=0, y=0, z=0):
        super().__init__(x, y)
        self.z = z

    def magnitude(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    @staticmethod
    def distance(p1, p2):
        return math.sqrt((p2.x - p1.x) ** 2 + (p2.y - p1.y) ** 2 + (p2.z - p1.z) ** 2)

    @staticmethod
    def dot_product(p1, p2):
        return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z

    @staticmethod
    def cross_product(p1, p2):
        return Point3D(
            p1.y * p2.z - p1.z * p2.y,
            p1.z * p2.x - p1.x * p2.z,
            p1.x * p2.y - p1.y * p2.x
        )

    def __repr__(self):
        return f"({self.x}, {self.y}, {self.z})"

if __name__ == "__main__":
    p1 = Point2D(3, 4)
    p2 = Point2D(6, 8)
    print(f"Magnitude of p1: {p1.magnitude()}")
    print(f"Rotation of p1: {p1.rotation()} degrees")
    print(f"Distance between p1 and p2: {Point2D.distance(p1, p2)}")
    print(f"Dot product of p1 and p2: {Point2D.dot_product(p1, p2)}")
    print(f"Cross product of p1 and p2: {Point2D.cross_product(p1, p2)}")

    p3 = Point3D(1, 2, 3)
    p4 = Point3D(4, 5, 6)
    print(f"\nMagnitude of p3: {p3.magnitude()}")
    print(f"Distance between p3 and p4: {Point3D.distance(p3, p4)}")
    print(f"Dot product of p3 and p4: {Point3D.dot_product(p3, p4)}")
    print(f"Cross product of p3 and p4: {Point3D.cross_product(p3, p4)}")

