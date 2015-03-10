#include "Limit.hpp"

#warning "TODO: copilian form for Limit"
Limit::Limit( int nbr ) :
	_nbr( nbr )
{
	(void)nbr;
	static int t = 1;
	srand(t++);
	addComponent( new Wall( Vec2i(0, 0), Vec2i(25, 0) ) );
	addComponent( new Wall( Vec2i(25, 0), Vec2i(25, 25) ) );
	addComponent( new Wall( Vec2i(25, 25), Vec2i(0, 25) ) );
	addComponent( new Wall( Vec2i(0, 25), Vec2i(0, 0) ) );

	for ( size_t i = 0; i < this->_nbr; i++ )
	{
		#warning "TODO: set limit for LimitElement correctly !"
		addComponent( new Wall( Vec2i( rand() % 25 , rand() % 25 ), Vec2i( rand() % 25 , rand() % 25 ) ) );
	}
	return ;
}

Limit::~Limit( void )
{
	return ;
}