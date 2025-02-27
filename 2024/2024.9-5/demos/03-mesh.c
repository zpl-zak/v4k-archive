#include "v4k.h"

int main() {
    window_create(75, 0);

    camera_t cam=camera();
    skybox_t sky=skybox(0, 0);
    model_t mdl=model(0, 0);

    model_vertex_t cube_vertices[] = {
        // Front face
        {{-1.0f, -1.0f,  1.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f, -1.0f,  1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f,  1.0f,  1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        // Back face
        {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f, -1.0f, -1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f,  1.0f, -1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f,  1.0f, -1.0f}, {0.0f, 1.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        // Left face
        {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f, -1.0f,  1.0f}, {1.0f, 0.0f}, {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f,  1.0f,  1.0f}, {1.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f,  1.0f, -1.0f}, {0.0f, 1.0f}, {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        // Right face
        {{ 1.0f, -1.0f, -1.0f}, {0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f, -1.0f,  1.0f}, {1.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f,  1.0f, -1.0f}, {0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        // Top face
        {{-1.0f,  1.0f, -1.0f}, {0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f,  1.0f,  1.0f}, {1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f,  1.0f, -1.0f}, {0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        // Bottom face
        {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-1.0f, -1.0f,  1.0f}, {1.0f, 0.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f, -1.0f,  1.0f}, {1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 1.0f, -1.0f, -1.0f}, {0.0f, 1.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, -1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        // Bottom plane, offseted by 0.5 units along Y axis
        {{-10.0f, -1.5f, -10.0f}, {0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{-10.0f, -1.5f,  10.0f}, {1.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 10.0f, -1.5f,  10.0f}, {1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
        {{ 10.0f, -1.5f, -10.0f}, {0.0f, 1.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 1.0f}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.0f, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}},
    };

    uint32_t cube_indices[] = {
        // Front face
        0, 1, 2, 2, 3, 0,
        // Back face
        4, 5, 6, 6, 7, 4,
        // Left face
        8, 9, 10, 10, 11, 8,
        // Right face
        12, 13, 14, 14, 15, 12,
        // Top face
        16, 17, 18, 18, 19, 16,
        // Bottom face
        20, 21, 22, 22, 23, 20,
        // Bottom plane, offseted by 0.5 units along Y axis
        24, 25, 26, 26, 27, 24,
    };

    model_sync(mdl, countof(cube_vertices), cube_vertices, countof(cube_indices), cube_indices);
    model_skybox(&mdl, sky);
    
    light_t sun=light();
    sun.cast_shadows = true;
    sun.diffuse = vec3(0.4, 0.4, 0.4);
    shadowmap_t sm=shadowmap(512, 4096);

    model_light(&mdl, 1, &sun);
    model_shadow(&mdl, &sm);

    while (window_swap() && !input(KEY_ESC)) {
        shadowmap_begin(&sm);
            while(shadowmap_step(&sm)) {
                shadowmap_light(&sm, &sun, cam.proj, cam.view);
                model_render(mdl, cam.proj, cam.view, mdl.pivot);
            }
        shadowmap_end(&sm);
        camera_freefly(&cam);

        skybox_render(&sky, cam.proj, cam.view);

        model_render(mdl, cam.proj, cam.view, mdl.pivot);
    }
    return 0;
}