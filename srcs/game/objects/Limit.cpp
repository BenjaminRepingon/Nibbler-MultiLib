#include "Limit.hpp"

#warning "TODO: copilian form for Limit"
Limit::Limit( float width, float height ) :
	_width( width ), _height( height )
{
	static int t = 1;
	srand(t++);
	addComponent( new LimitSide( Vec2i(0, 0), Vec2i(this->_width, 0) ) );
	addComponent( new LimitSide( Vec2i(this->_width, 0), Vec2i(this->_width, this->_height) ) );
	addComponent( new LimitSide( Vec2i(this->_width, this->_height), Vec2i(0, this->_height) ) );
	addComponent( new LimitSide( Vec2i(0, this->_height), Vec2i(0, 0) ) );

	// for ( size_t i = 0; i < this->_nbr; i++ )
	// {
	// 	#warning "TODO: set limit for LimitElement correctly !"
	// 	addComponent( new LimitSide( Vec2i( rand() % 25 , rand() % 25 ), Vec2i( rand() % 25 , rand() % 25 ) ) );
	// }
	return ;
}

Limit::~Limit( void )
{
	return ;
}