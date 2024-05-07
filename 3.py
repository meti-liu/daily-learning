import math


#################### Begin #######################
def yPattern(cv_small):
    cv_small.delete("all")  # 清除画布
    cv_small.create_line(30, 10, 90, 70, fill='red', width=2)
    cv_small.create_line(150, 10, 90, 70, fill='red', width=2)
    cv_small.create_line(90, 140, 90, 70, fill='red', width=2)


def Y_tree(depth, percent, left_angle, right_angle, start_point, angle, length, canvas):
    if depth == 0:
        return
    end_point = (start_point[0] + length * math.cos(math.radians(angle)),
                 start_point[1] - length * math.sin(math.radians(angle)))
    canvas.create_line(start_point, end_point, fill='LightBlue4', width=2)
    Y_tree(depth - 1, percent, left_angle, right_angle, end_point, angle + right_angle, length * percent,
           canvas)  # 画右枝
    Y_tree(depth - 1, percent, left_angle, right_angle, end_point, angle - left_angle, length * percent,
           canvas)  # 画左枝
root=tk.Tk()
##################### End ########################