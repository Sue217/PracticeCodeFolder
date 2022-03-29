
# Author: 苏靖博(sudo BOBLT)
# Number: 20105050110
# Class: 计实验20

import turtle

def circle(radius, extent=None, fc='white'):

    turtle.setheading(dia)
    turtle.forward(radius)
    turtle.left(90)
    turtle.down()
    turtle.fillcolor(fc)
    turtle.begin_fill()
    turtle.circle(radius, extent)
    turtle.end_fill()
    turtle.up()
    turtle.right(90)
    turtle.back(radius)

num = 8
dia = num
turtle.hideturtle()
while True:
    turtle.goto(0, 0)
    turtle.tracer(0, 0)

    circle(200, extent=180, fc='black')

    circle(200, extent=-180)

    turtle.forward(100)
    circle(100, extent=-180, fc='black')

    turtle.back(200)
    circle(100, extent=180)

    circle(33, fc='black')

    turtle.back(200)
    circle(30)

    turtle.tracer(1, 10)

    dia += num
    if dia > 360:
        dia -= 360