#ifndef LIMIT_HPP
# define LIMIT_HPP
# include "../../core/GameObject.hpp"
# include "../components/Wall.hpp"

class Limit : public GameObject
{
public:
	// Limit( void );
	Limit( int nbr );
	~Limit( void );

private:
	size_t						_nbr;
};

#endif
