import numpy as np
from keras.models import model_from_json
from keras.preprocessing import image
import matplotlib.pyplot as plt
from pathlib import Path
import json

def getCoords(ind):
	x = 0
	y = 0
	width = 0
	height = 0
	with open('patterns\\History.json') as report:
	    data = json.load(report)
	    x = data["questions"][ind]["x"]
	    y = data["questions"][ind]["y"]
	    width = data["questions"][ind]["width"]
	    height = data["questions"][ind]["height"]


	return x,y,width,height

# Загружаем изображение

json_file = open("mnist_model.json", "r")
loaded_model_json = json_file.read()
json_file.close()
loaded_model = model_from_json(loaded_model_json)
loaded_model.load_weights("mnist_model.h5")
loaded_model.compile(loss="categorical_crossentropy", optimizer="adam", metrics=["accuracy"])
fl = open('info.txt', 'r')
numbImage = fl.readline()
fl.close()
f = open('text.txt', 'w')
for numb in range(int(numbImage)):
	rt = numb + 1
	img_path = "images\\" + str(rt) + '.png'

	
	#x,y,width,height = getCoords(numb)
	#print(x,y,width,height)

	#img = imag.crop((int(x), int(y), int(width), int(height) ))
	#img = image.load_img(imgfile, target_size=(int(x), int(y), int(width), int(height)))
	#qwe = img
	img = image.load_img(img_path, target_size=(28, 28), grayscale=True)
	#plt.imshow(img, cmap='gray')
	#plt.show()


	# Преобразуем изображением в массив numpy
	x = image.img_to_array(img)

	# Инвертируем и нормализуем изображение
	x = 255 - x
	x /= 255
	x = np.expand_dims(x, axis=0)

	

	prediction = loaded_model.predict(x)
	qwe = np.argmax(prediction)
	#print(qwe)
	#print(numb, " ", numbImage)
	if int(numb + 1) == int(numbImage):
		f.write(str(qwe))
	else:
		f.write(str(qwe) + str("&"))
f.close()