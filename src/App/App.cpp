#include <App.h>

App::App()
{

}

App::~App()
{
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
}

bool App::init()
{
    // Initialise GLFW
    if( !glfwInit() )
    {
            fprintf( stderr, "Failed to initialize GLFW\n" );
            return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( 1024, 768, "Quasar", NULL, NULL);
    if( window == NULL ){
            glfwTerminate();
            return false;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
            fprintf(stderr, "Failed to initialize GLEW\n");
            return false;
    }

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.02f, 0.0f);


    planet = new Planet();
    camera.setPosition(vec3(0,2,-1));
    camera.setTarget(vec3(0,0,0));

    return true;
}

void App::run()
{
    if(!init())
        return;

    glfwSetTime(0);
    while(!glfwWindowShouldClose(window))
    {
        update(glfwGetTime());
        //cout << "FPS " << 1./glfwGetTime() << " (" << glfwGetTime() << ")" << endl;
        glfwSetTime(0);
        draw();
    }
}
void App::update(double diff)
{
    glfwPollEvents();

}

void App::draw()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    planet->draw(&camera);


    // Swap buffers
    glfwSwapBuffers(window);
}
