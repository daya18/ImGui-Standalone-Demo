#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

int main()
{
	glfwInit ();

	auto window { glfwCreateWindow ( 1280, 720, "ImGui-Standalone-Demo", nullptr, nullptr ) };
	glfwMakeContextCurrent ( window );

	auto imGuiContext { ImGui::CreateContext () };
	ImGui::SetCurrentContext ( imGuiContext );

	ImGui_ImplGlfw_InitForOpenGL ( window, true );
	ImGui_ImplOpenGL3_Init ();

	while ( ! glfwWindowShouldClose ( window ) )
	{
		glfwPollEvents ();

		glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		ImGui_ImplGlfw_NewFrame ();
		ImGui_ImplOpenGL3_NewFrame ();
		
		ImGui::NewFrame ();

		ImGui::ShowDemoWindow ();

		ImGui::EndFrame ();

		ImGui::Render ();
		ImGui_ImplOpenGL3_RenderDrawData ( ImGui::GetDrawData () );
		
		glfwSwapBuffers ( window );
	}

	ImGui_ImplOpenGL3_Shutdown ();
	ImGui_ImplGlfw_Shutdown ();
	ImGui::DestroyContext ( imGuiContext );
	glfwDestroyWindow ( window );
	glfwTerminate ();

	return 0;
}
