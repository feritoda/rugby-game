// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

static int turn = 0;

/*----------------------------------------------------------------------------*/
/*                          PRIVATE FUNCTIONS HEADERS                         */
/*----------------------------------------------------------------------------*/

bool equal_directions2(direction_t d1, direction_t d2);

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  // TODO: unused parameters, remove these lines later
  UNUSED(defender_position);
  UNUSED(attacker_spy);

  // TODO: Implement Defender logic here
  static direction_t best_direction;
  static position_t attacker_position;
  static int distance; 

  if (turn == 0)
    best_direction = (direction_t) DIR_LEFT;

  if (turn == 1){
    attacker_position = get_spy_position(attacker_spy);
    
    distance = defender_position.j - attacker_position.j;

    if (attacker_position.i < defender_position.i)
      best_direction = (direction_t) DIR_UP;
    
    else if (attacker_position.i > defender_position.i)
      best_direction = (direction_t) DIR_DOWN;
  }

  if (equal_directions2(best_direction, (direction_t) DIR_DOWN) ||
      equal_directions2(best_direction, (direction_t) DIR_DOWN_LEFT)){
    if (turn - 1 <= distance / 2)
      best_direction = (direction_t) DIR_DOWN_LEFT;
    else
      best_direction = (direction_t) DIR_STAY;
  }

  else if (equal_directions2(best_direction, (direction_t) DIR_UP) ||
            equal_directions2(best_direction, (direction_t) DIR_UP_LEFT)){
    if (turn - 1 <= distance / 2)
      best_direction = (direction_t) DIR_UP_LEFT;
    else
      best_direction = (direction_t) DIR_STAY;
  
  }
    
      
  turn++;
  return best_direction;


}

/*----------------------------------------------------------------------------*/
/*                             PRIVATE FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

bool equal_directions2 (direction_t d1, direction_t d2){
  return d1.i == d2.i && d1.j == d2.j;
}

/*----------------------------------------------------------------------------*/
