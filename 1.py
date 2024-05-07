import tkinter as tk

root = tk.Tk()
root.geometry('970x750')
cv_big_width = 880
cv_big_height = 690
# 大画布的宽度和高度变量，方便后期调整
############## Begin ##############
# 创建蓝色边框的大画布
cv_big = tk.Canvas(root, bg="white", highlightthickness=1,  highlightbackground="LightBlue")
cv_big.config(width=cv_big_width,height=cv_big_height)
cv_big.place(x=30, y=10, anchor='nw')

# 创建红色边框的小画布
cv_small_width = cv_big_width // 4
cv_small_height = cv_big_height // 4
cv_small = tk.Canvas(root, bg="white", highlightthickness=1, highlightbackground="tomato")
cv_small.config(width=cv_small_width, height=cv_small_height)
cv_small.place(x=30, y=cv_big_height, anchor='sw')
############## End ################
root.mainloop()