#pragma once
#include <engine.h>
#include "player.h"
#include "billboard.h"
#include "bounding_box.h"

class pickup;

class example_layer : public engine::layer
{
public:
    example_layer();
	~example_layer();

    void on_update(const engine::timestep& time_step) override;
    void on_render() override; 
    void on_event(engine::event& event) override;

private:
	void check_bounce();
	void hexagon_shape();

	engine::ref<engine::skybox>			m_skybox{};
	engine::ref<engine::game_object>	m_terrain{};
	engine::ref<engine::game_object>	m_cow{};
	engine::ref<engine::game_object>	m_tree{};
	engine::ref<engine::game_object>	m_ball{};
	engine::ref<engine::game_object>	m_jeep{};
	engine::ref<engine::game_object>	m_rusted_car{};
	engine::ref<engine::game_object>	m_car{};
	engine::ref<engine::game_object>	m_mannequin{};
	engine::ref<engine::game_object>	m_tetrahedron{};
	engine::ref<engine::game_object>	m_box{};
	engine::ref<engine::game_object>	m_rectangle{};
	engine::ref<engine::game_object>	m_fence{};
	engine::ref<pickup>					m_pickup{};
	player								m_player{};
	bounding_box						m_player_box;
	bounding_box						m_fence_box;
	std::string score = "0";
	int x = 0;
	int y = 1;
	engine::ref<engine::material>		m_material{};
	engine::ref<engine::material>		m_tetrahedron_material{};
	engine::ref<engine::material>		m_box_material{};

	engine::DirectionalLight            m_directionalLight;

	std::vector<engine::ref<engine::game_object>>     m_game_objects{};

	engine::ref<engine::bullet_manager> m_physics_manager{};
	engine::ref<engine::audio_manager>  m_audio_manager{};
	float								m_prev_sphere_y_vel = 0.f;
	engine::ref<engine::text_manager>	m_text_manager{};

    engine::orthographic_camera       m_2d_camera; 
    engine::perspective_camera        m_3d_camera;
	 
	engine::ref<billboard>							m_billboard{};

	bool m_fog = false;
	glm::vec3 m_fog_colour;
	int32_t m_fog_factor_type;
};
