#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

// -*- C++ -*-
// $Id: Mod_Command.h

//==============================================================================
/**
 * @file       Mod_Command.h
 *
 * $Id: Mod_Command.h
 *
 */
//==============================================================================

/**
 * @class Mod_Command
 *
 *
 */

#include "Binary_command.h"

class Mod_Command : public Binary_Command
{
public:
  /**
   * constructor
   * @param[in] stack
   */
  Mod_Command(Stack<int> &s);
  /**
   * evaluate
   * @param[in] num_1, num_2
   */
  int evaluate(int num_1, int num_2) const;
  /**
   * destructor
   */
};

#endif