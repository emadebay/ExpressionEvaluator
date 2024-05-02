#ifndef _COMMAND_H
#define _COMMAND_H

// -*- C++ -*-
// $Id: Command.h

//==============================================================================
/**
 * @file       Command.h
 *
 * $Id: Command.h
 *
 */
//==============================================================================

/**
 * @class Command
 * This class is the parent of all commands type
 * that is, this class is the ancestor for all commands
 *it defines some core functionality of its children
 *by using the template pattern
 */

class Command
{

public:
    /**
     * default constructor
     *
     */
    Command(void);
    /**
     * constructor
     * @param[in] assigned_num_of_precedence
     */

    Command(int assigned_num_of_precedence);
    /**
     * destructor
     */
    virtual ~Command(void);
    /**
     * execute
     * virtual method
     * defines or templates what sublcasses should do
     */
    virtual void execute(void) = 0;

    /**
     * precedence_value
     * returns order of precedence
     */
    int precedence_value() const;

private:
    int assigned_num_of_precedence_;
};

#endif