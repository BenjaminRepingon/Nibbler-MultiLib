#ifndef FOOD_HPP
# define FOOD_HPP
# include "../../core/GameObject.hpp"
# include "../components/FoodElement.hpp"

class Food : public GameObject
{
public:
	// Food( void );
	Food( int nbr );
	~Food( void );

	virtual int					update( ILib const * lib, double delta );


private:
	size_t						_nbr;
};

#endif
