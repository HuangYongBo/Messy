list :列表
tuple:元组

list可被修改,tuple不可被修改
list用[],tuple用();
声明tuple时,如果只有一个元项,则需要加,以让编译器知道,如test = ('hello',)











变量包含对列表值的引用,而不是列表本身.但对于字符串和整数值,变量就包含了对字符串或整数值.在变量必须保存可变数据类型的值时,例如列表或字典,python就使用引用.对于不可变的数据类型的值,例如字符串/整型或元组,python变量就保存值本身.



list的方法:
list_t.append:
  说明:append(...) method of builtins.list instance
      L.append(object) -> None -- append object to end

list_t.count    :
  说明:count(...) method of builtins.list instance
    L.count(value) -> integer -- return number of occurrences of value

list_t.insert   :
  说明:insert(...) method of builtins.list instance
    L.insert(index, object) -- insert object before index

list_t.reverse:
  说明:reverse(...) method of builtins.list instance
    L.reverse() -- reverse *IN PLACE*
list_t.clear    :
  说明:clear(...) method of builtins.list instance
    L.clear() -> None -- remove all items from L

list_t.extend   :
  说明:extend(...) method of builtins.list instance
    L.extend(iterable) -> None -- extend list by appending elements from the iterable

list_t.pop      :
  说明:pop(...) method of builtins.list instance
    L.pop([index]) -> item -- remove and return item at index (default last).
    Raises IndexError if list is empty or index is out of range.

list_t.sort:
  说明:sort(...) method of builtins.list instance
    L.sort(key=None, reverse=False) -> None -- stable sort *IN PLACE*

list_t.copy     :
  说明:copy(...) method of builtins.list instance
    L.copy() -> list -- a shallow copy of L

list_t.index    :
  说明:index(...) method of builtins.list instance
    L.index(value, [start, [stop]]) -> integer -- return first index of value.
    Raises ValueError if the value is not present.

list_t.remove   :
  说明:emove(...) method of builtins.list instance
    L.remove(value) -> None -- remove first occurrence of value.
    Raises ValueError if the value is not present.
