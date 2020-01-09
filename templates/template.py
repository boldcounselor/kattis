""" Answer a specific exercise of a programming contest.
This module contains all the code needed to answer a given exercise during a
programming contest. Due to its quick creation and the fact that it's probably
not following proper Python guidelines (as described in multiples PEP
documents), it shouldn't be used in production.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.
"""

import statistics
import math
import datetime
import collections


__author__ = "Bizzozzéro Nicolas"
__contact__ = "nicolasbizzozzero[at]gmail.com"
__copyright__ = "Copyright YYYY, Bizzozzéro Nicolas"
__date__ = "YYYY/MM/DD"
__license__ = "GPLv3"


def identity(*args):
    """ Always returns the same value that was used as its argument.
    Example:
    >>> identity(1)
    1
    >>> identity(1, 2)
    (1, 2)
    """
    if len(args) == 1:
        return args[0]
    return args


def parsin(*, l=1, vpl=1, cf=identity, s=" "):
    """ Can parse inputs usually used in competitive programming problems.
    Arguments:
    - l, as in "Lines", the number of lines to parse at once.
    - vpl, as in "Values Per Line", the number of values to parse per line.
    - cf, as in "Cast Function", the function to apply to each parsed element.
    - s, as in "Separator", the string separating multiple values in the same
      line.
    """
    if l == 1:
        if vpl == 1:
            return cf(input())
        else:
            return list(map(cf, input().split(s)))
    else:
        if vpl == 1:
            return [cf(input()) for _ in range(l)]
        else:
            return [list(map(cf, input().split(s)))
                    for _ in range(l)]


def main():
    pass


if __name__ == '__main__':
    main()