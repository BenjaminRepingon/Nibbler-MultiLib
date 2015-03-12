#include "Food.hpp"

#warning "TODO: copilian form for Food"
Food::Food( int nbr ) :
	_nbr( nbr )
{
	return ;
}

Food::~Food( void )
{
	return ;
}

void		Food::init( void )
{
	for ( size_t i = 0; i < this->_nbr; i++ )
	{
		#warning "TODO: set limit for FoodElement correctly !"
		addComponent( new FoodElement( Vec2i( rand() % 10 , rand() % 10 ) ) );
	}
	addComponent( new PotionElement( Vec2i( -1 , -1 ) ) );
}