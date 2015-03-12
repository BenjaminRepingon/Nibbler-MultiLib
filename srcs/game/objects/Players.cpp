#ifndef PLAYERS_HPP
# define PLAYERS_HPP
# include "../../core/GameObject.hpp"
# include "../components/Player.hpp"

class Limit : public GameObject
{
public:
	// Limit( void );
	Players( float width, float height );
	~Players( void );
	virtual void				init( void );

private:
	float						_width;
	float						_height;
};

#endif
