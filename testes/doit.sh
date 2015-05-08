#!/bin/bash
./test < test01.in > test01.myout && diff test01.out test01.myout
./test < test02.in > test02.myout && diff test02.out test02.myout
./test < test03.in > test03.myout && diff test03.out test03.myout
./test < test04.in > test04.myout && diff test04.out test04.myout
./test < test05.in > test05.myout && diff test05.out test05.myout
./test < test06.in > test06.myout && diff test06.out test06.myout
./test < test07.in > test07.myout && diff test07.out test07.myout
./test < test08.in > test08.myout && diff test08.out test08.myout
