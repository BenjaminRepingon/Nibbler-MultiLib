#ifndef LABYRINTHE_HPP
# define LABYRINTHE_HPP
# include "../../core/GameObject.hpp"
# include "../components/Wall.hpp"

class Labyrinthe : public GameObject
{
public:
	// Labyrinthe( void );
	Labyrinthe(  float width, float height, int nbr );
	~Labyrinthe( void );
	virtual void				init( void );

private:
	float						_width;
	float						_height;
	int 						_nbr;
};

#endif