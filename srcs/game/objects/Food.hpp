#ifndef FOOD_HPP
# define FOOD_HPP
# include "../../core/GameObject.hpp"
# include "../components/FoodElement.hpp"
# include <cstdlib> 

class Food : public GameObject
{
public:
	// Food( void );
	Food( int nbr );
	~Food( void );

	virtual int					update( ILib const * lib, double delta );
	virtual void				init( void );


private:
	size_t						_nbr;
};

#endif
