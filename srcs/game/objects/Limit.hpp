#ifndef LIMIT_HPP
# define LIMIT_HPP
# include "../../core/GameObject.hpp"
# include "../components/LimitSide.hpp"

class Limit : public GameObject
{
public:
	// Limit( void );
	Limit( float width, float height );
	~Limit( void );

private:
	float						_width;
	float						_height;
};

#endif
