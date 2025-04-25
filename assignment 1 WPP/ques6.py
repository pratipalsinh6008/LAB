'''Consider a 3-D co-ordinate space. Input 10 3-D points. Find the nearest neighbour for each
of the points in your 3-D space and store them in a list. The final output is a list with each
consisting of a point and its nearest neighbour. [Hint: Use distance between two points
formula]'''
import math


def cal_len(point1, point2):
    return math.sqrt((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2 + (point1[2] - point2[2]) ** 2)


points = []
print("Enter 10 3D points:")
for i in range(10):
    print(f"Point {i + 1}:")
    x = float(input("Enter x-coordinate: "))
    y = float(input("Enter y-coordinate: "))
    z = float(input("Enter z-coordinate: "))
    points.append((x, y, z))


nearest_neighbour = []
for i in range(len(points)):
    current_point = points[i]
    min_distance = float('inf')
    nearest_point = None
    for j in range(len(points)):
        if i != j:
            distance = cal_len(current_point, points[j])
            if distance < min_distance:
                min_distance = distance
                nearest_point = points[j]
    nearest_neighbour.append((current_point, nearest_point))


print("\nPoints and their nearest neighbours:")
for pair in nearest_neighbour:
    print(f"Point= {pair[0]} and its Nearest Neighbour= {pair[1]}")
