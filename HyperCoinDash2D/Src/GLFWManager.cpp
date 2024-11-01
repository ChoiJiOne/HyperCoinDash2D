#include "GLFWManager.h"
#include "MemoryAlloc.h"

#define GL_MAJOR_VERSION 4
#define GL_MINOR_VERSION 6

GLFWManager GLFWManager::singleton_;

void GLFWErrorCallback(int32_t errorCode, const char* description)
{
	GLFWManager::GetRef().SetLsatError(errorCode, description);
}

GLFWManager& GLFWManager::GetRef()
{
	return singleton_;
}

GLFWManager* GLFWManager::GetPtr()
{
	return &singleton_;
}

void GLFWManager::SetLsatError(int32_t code, const char* message)
{
	bIsDetectError_ = true;
	errorCode_ = code;
	errorMessage_ = message;
}

void GLFWManager::Startup(int32_t width, int32_t height, const char* title)
{
	glfwSetErrorCallback(GLFWErrorCallback);

	GLFWallocator allocator;
	allocator.allocate = MemoryAlloc;
	allocator.reallocate = MemoryRealloc;
	allocator.deallocate = MemoryFree;

	glfwInitAllocator(&allocator);
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_MINOR_VERSION);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mainWindow_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

void GLFWManager::Shutdown()
{
	if (mainWindow_)
	{
		glfwDestroyWindow(mainWindow_);
		mainWindow_ = nullptr;
	}

	glfwTerminate();
}
