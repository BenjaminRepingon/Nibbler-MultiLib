#include "Player.hpp"

#warning "TODO: copilian form for Player"
Player::Player( Vec2i const & pos ):
_score( 0 );
{
	setPos( pos );
	return ;
}

Player::~Player( void )
{
	return ;
}

int			Player::update( ILib const * lib, double delta )
{

	(void)lib;
	(void)delta;
	return ( true );
}

int			Player::render( ILib const * lib ) const
{
	lib->drawSquare( this->_pos.getX(), this->_pos.getY(), 1, 0x318CE7 );
	return ( true );
}
