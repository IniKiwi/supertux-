//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <iosfwd>
#include <optional>
#include <string>

enum class Control {
  LEFT = 0,
  RIGHT,
  UP,
  DOWN,

  JUMP,
  ACTION,
  ITEM,

  START,
  ESCAPE,
  MENU_SELECT,
  MENU_SELECT_SPACE,
  MENU_BACK,
  REMOVE,

  CHEAT_MENU,
  DEBUG_MENU,
  CONSOLE,

  PEEK_LEFT,
  PEEK_RIGHT,
  PEEK_UP,
  PEEK_DOWN,

  CONTROLCOUNT
};

std::ostream& operator<<(std::ostream& os, Control control);

std::string Control_to_string(Control control);
std::optional<Control> Control_from_string(const std::string& text);

class Controller
{
public:
  Controller();
  virtual ~Controller();

  virtual void update();

  void set_control(Control control, bool value);

  void set_jump_key_with_up(bool value);

  /** Touchscreen flag is set by MobileController, cleared when starting the level */
  inline void set_touchscreen(bool value) { m_touchscreen = value; }

  /** returns true if the control is pressed down */
  bool hold(Control control) const;

  /** returns true if the control has just been pressed down this frame */
  bool pressed(Control control) const;

  template<typename... Control>
  bool pressed_any(Control&&... controls) const
  {
    for(const auto& control : {controls... })
    {
      if(pressed(control))
        return true;
    }
    return false;
  }

  /** returns true if the control has just been released this frame */
  bool released(Control control) const;

  void reset();

  /** returns true if the controller event has been generated by touchscreen */
  inline bool is_touchscreen() const { return m_touchscreen; }

protected:
  /** current control status */
  bool m_controls[static_cast<int>(Control::CONTROLCOUNT)];

  /** control status at last frame */
  bool m_old_controls[static_cast<int>(Control::CONTROLCOUNT)];

  /** the event has been generated by touchscreen */
  bool m_touchscreen;

  /** the jump key is pressed for this controller */
  bool m_jump_key_pressed;

private:
  Controller(const Controller&) = delete;
  Controller& operator=(const Controller&) = delete;
};
