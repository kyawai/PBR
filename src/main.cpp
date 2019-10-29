#include <SDL2/SDL.h>
#include <exception>
#include <GL/glew.h>
#include <fstream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "stb_image.h"
#include "Texture.h"
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <string.h>


//PUBLIC VERIABLES 

int windowWidth = 800;
int windowHeight = 600;
int main(int argc, char *argv[])
{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
				throw std::exception();
		}


		SDL_Window *window = SDL_CreateWindow("Triangle",        //CREATE WINDOW
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(window))
		{
				throw std::exception();
		}
		if (glewInit() != GLEW_OK)
		{
				throw std::exception();
		}

		//GET OBJECTS AND TEXTURES

		//VertexArray *car = new VertexArray("../Car.obj");                                  //example of adding object and its texture
		//Texture *texture = new Texture("../Car.png");

		glm::mat4 model(1.0f);
		//SHADER PROGRAM FOR PERSPECTIVE PROJECTION
		ShaderProgram *shaderProgram = new ShaderProgram("../shaders/simple.vert.txt", "../shaders/simple.frag.txt");   //shader program


		//SET THE CAMERA POSITION
		glm::vec3 cameraPos(0.3, 0, 10);
		//BOOL TO QUIT THE GAME
		bool quit = false;
		//SET CULLING AND DEPTH TESTING
		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

		//START THE GAME
		while (!quit)
		{
				SDL_Event event = { 0 };  //CREATE THE FIRST EVENT, SET UP AND CALCULATE TIME 
				while (SDL_PollEvent(&event))
				{
						if (event.type == SDL_QUIT)
						{
								quit = true;
						}
				}

				//SET UP PERSPECTIVE PROJECTION
				model = glm::mat4(1.0f);
				SDL_GetWindowSize(window, &windowWidth, &windowHeight);
				glViewport(0, 0, windowWidth, windowHeight);
				glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				shaderProgram->SetUniform("in_Projection", glm::perspective(glm::radians(45.0f),
						(float)windowWidth / (float)windowHeight, 0.1f, 1000.f));
				model = glm::translate(model, glm::vec3(0, 0, -2.5f));
				shaderProgram->SetUniform("in_Model", model);

				glActiveTexture(GL_TEXTURE + 1);

				//SET UP THE LIGHT POSITION
				shaderProgram->SetUniform("in_LightPos", glm::vec3(50, 100, 50));


				// CREAT THE CAMERA
				glm::mat4 t(1.0f);
				model = glm::translate(model, glm::vec3(3, 1.5, -105));
				model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0.06));
				shaderProgram->SetUniform("in_Model", model);
				shaderProgram->SetUniform("in_View", glm::inverse(model));

				//DRAWING OBJECTS
				//model = glm::mat4(1.0f);
				//model = glm::scale(model, glm::vec3(10.0f, 10.0f, 10.0f));
				//model = glm::translate(model, glm::vec3(mainCar, -11.5, carZ));
				//shaderProgram->SetUniform("in_Model", model);
				//shaderProgram->setUniform("in_Texture", texture);
				//shaderProgram->draw(car);
				//SWAP WINDOWS, THIS WAY THE MODELS AND TEXTURES ARE DISPLAYED
				SDL_GL_SwapWindow(window);
		}
		//DELETE
		SDL_DestroyWindow(window);
		SDL_Quit();
		delete shaderProgram;
		return 0;
}
