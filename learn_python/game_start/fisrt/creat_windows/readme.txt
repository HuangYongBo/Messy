
screen = pygame.display.set_mode((480,852),0,32)

background = pygame.image.load("file_path")

while True:
	screen.blit(background,(0,0))
	
	pygame.display.update()
	

获取事件:
from  pygame.locals import *
for event in pygame.event.get():
	if event.type == QUIT:
		exit()

	elif event.type ==KEYDOWN:
		if event.key = K_a or event.key == K_LEFT:
			pass
		elif event.key == K_d or event.key == K_RIGHT:
			pass
		elif event.key ==  K_SPACE:
		
