import pygame
from pygame.locals import *
pygame.init()
screen = pygame.display.set_mode((500,500))
myfont=pygame.font.Font(None,60)
white = 255,255,255
blue = 0,0,255
textImage=myfont.render("boy",True,white)
while True:
	for event in pygame.event.get():
		if event.type in (QUIT,KEYDOWN):
			sys.exit()
	screen.fill(blue)
	screen.blit(textImage,(100,100))
	pygame.display.update()

