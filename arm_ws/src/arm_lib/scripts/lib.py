
import cv2 as cv
import numpy as np
img=cv.imread("index.jpeg",cv.IMREAD_GRAYSCALE)
filter=np.array([
[-1,0,1],
[-2,0,2],
[-1,0,1]
])
k=3

new_img=np.zeros_like(img)

for i in range(img.shape[0]-2):
 for j in range(img.shape[1]-2):
  patch=img[i:i+k,j:j+k]
  Gx= (filter * patch).sum()
  Gy=(filter.T * patch).sum()
  G=np.sqrt(Gx**2 + Gy**2)
  new_img[i,j]=G
 
cv.imshow("Display Window",new_img)
cv.waitKey(0)
