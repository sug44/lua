This is Lua 5.4.7 with *a bit* of syntactic sugar.

**Expression-body function declaration:**
Whenever an expression is expected `> *expression*` works like `function() return *expression* end`. There is an optional `;` after the expression. Mainly it allows for C# like `variable => *expression*` syntax.
For now `.>` token can also be used because while being a syntax error its not showing up as such with LuaLS. This might be a temporary hack that later will be replaced with a LuaLS plugin

For installation instructions, license details, and
further information about Lua, see doc/readme.html.
