# OBJ_uzduotys

# Files
main_vector.cpp
main_lsit.cpp
main_deque.cpp

headers_vector.h
headers_list.h
headers_deque.h
includes.h

Makefile

# Releases
v0.1 - šioje versijoje yra du failai main.cpp, kuris skaičiuoja vidurkį naudojant C masyvus, vektoriai.cpp, kuris skaičiuoja vidurkį naudojant vectors.

v0.11 - ši versija tokia pati kaip ir v0.1, bet main.cpp faile vietoje statiniu C masyvu yra naudojami dinaminei masyvai.

v0.2 - šioje versijoje buvo pridėta galimybė nuskaityti studentų informaciją nuo tekstinio failo.

v0.3 - šioje versijoje buvo pridėtas klaidų gaudymas ir išskaidyta į kelis failus main.cpp, kuriame yra pagrindinė versija, headers.h, kuriame deklaruotos funkcijos ir structas, includes.h, kuriame pridėtos visos naudojamos bibliotekos.

v0.4 - šioje versijoje buvo pridėta galimybė generuoti tekstinius failus ir padlinti studentai į dvi grupes pirma grupė, kurių vidurkis > 5 kita kurių vidurkis < 5.

v0.41 ir v0.42 - identiškos v0.4 tik aptvarkytas kodas.

v1.0 - Programa realizuota su vector, list ir deque. Implementuotos ir testuotos trys studentų dalijimo į dvi dalis strategijos ir testuotas jų efektyvumas.

v1.01 - Programa ta pati kaip ir v1.0 apart pridėtas Makefile.

# Naudojimo instrukcija



# Test files
Studentai1000.txt
Studentai10000.txt
Studentai100000.txt
Studentai1000000.txt
Studentai10000000.txt

# Hardware

CPU: Ryzen 5 5600X
RAM: 32GB 3200 MHz
SSD: KINGSTON SA400S37240G, Write: 450 MB/s, Read: 500 MB/s

# Tests using vectors
1000 nariu;

Test 1:
Failo skaitymas:    0.000616s
Failo rusiavimas:   0.000396s
Isvedimas 1:        0.005643s
Isvedimas 2:        0.004579s

Test 2:
Failo skaitymas:    0.000671s
Failo rusiavimas:   0.000457s
Isvedimas 1:        0.006457s
Isvedimas 2:        0.004790s

10000 nariu;

Test 1:
Failo skaitymas:    0.000647s
Failo rusiavimas:   0.004280s
Isvedimas 1:        0.048408s
Isvedimas 2:        0.040167s

Test 2:
Failo skaitymas:    0.000390s
Failo rusiavimas:   0.004237s
Isvedimas 1:        0.055388s
Isvedimas 2:        0.036150s

100000 nariu;

Test 1:
Failo skaitymas:    0.001498s
Failo rusiavimas:   0.033884s
Isvedimas 1:        0.521535s
Isvedimas 2:        0.362521s

Test 2:
Failo skaitymas:    0.001447s
Failo rusiavimas:   0.034752s
Isvedimas 1:        0.538185s
Isvedimas 2:        0.382430s

1000000 nariu;

Test 1:
Failo skaitymas:    0.003555s
Failo rusiavimas:   0.335967s
Isvedimas 1:        6.566506s
Isvedimas 2:        4.211092s

Test 2:
Failo skaitymas:    0.004582s
Failo rusiavimas:   0.337532s
Isvedimas 1:        6.116795s
Isvedimas 2:        4.285555s

10000000 nariu;

Test 1:
Failo skaitymas:    0.029089s
Failo rusiavimas:   3.214557s
Isvedimas 1:        67.729387s
Isvedimas 2:        47.8363335s

Test 2:
Failo skaitymas:    0.030963s
Failo rusiavimas:   3.222774s
Isvedimas 1:        67.525903s
Isvedimas 2:        46.838125s

# Tests using Lists

1000 nariu;

Test 1:
Failo skaitymas:    0.000335s
Failo rusiavimas:   0.002437s
Isvedimas 1:        0.008945s
Isvedimas 2:        0.006665s

Test 2:
Failo skaitymas:    0.000519s
Failo rusiavimas:   0.002233s
Isvedimas 1:        0.009080s
Isvedimas 2:        0.006317s

10000 nariu;

Test 1:
Failo skaitymas:    0.001118s
Failo rusiavimas:   0.022681s
Isvedimas 1:        0.088044s
Isvedimas 2:        0.062896s

Test 2:
Failo skaitymas:    0.002078s
Failo rusiavimas:   0.022538s
Isvedimas 1:        0.094549s
Isvedimas 2:        0.067478s

100000 nariu;

Test 1:
Failo skaitymas:    0.002675s
Failo rusiavimas:   0.223838s
Isvedimas 1:        1.087644s
Isvedimas 2:        0.784492s

Test 2:
Failo skaitymas:    0.001630s
Failo rusiavimas:   0.232074s
Isvedimas 1:        1.089013s
Isvedimas 2:        0.771690s

1000000 nariu;

Test 1:
Failo skaitymas:    0.006676s
Failo rusiavimas:   2.204351s
Isvedimas 1:        14.430556s
Isvedimas 2:        9.657494s

Test 2:
Failo skaitymas:    0.005759s
Failo rusiavimas:   2.206512s
Isvedimas 1:        14.577888s
Isvedimas 2:        9.606979s

10000000 nariu;

Test 1:
Failo skaitymas:    0.053894s
Failo rusiavimas:   22.090134s
Isvedimas 1:        175.311462s
Isvedimas 2:        118.747958s

Test 2:
Failo skaitymas:    0.058258s
Failo rusiavimas:   21.944877s
Isvedimas 1:        174.597436s
Isvedimas 2:        118.469033s

# Tests using Deque

1000 nariu;

Test 1:
Failo skaitymas:    0.000768s
Failo rusiavimas:   0.001047s
Isvedimas 1:        0.044239s
Isvedimas 2:        0.056020s

Test 2:
Failo skaitymas:    0.000732s
Failo rusiavimas:   0.001050s
Isvedimas 1:        0.010236s
Isvedimas 2:        0.006744s

10000 nariu;

Test 1:
Failo skaitymas:    0.000995s
Failo rusiavimas:   0.011214s
Isvedimas 1:        0.101602s
Isvedimas 2:        0.073698s

Test 2:
Failo skaitymas:    0.001784s
Failo rusiavimas:   0.010225s
Isvedimas 1:        0.100326s
Isvedimas 2:        0.087062s

100000 nariu;

Test 1:
Failo skaitymas:    0.009809s
Failo rusiavimas:   0.104245s
Isvedimas 1:        1.130787s
Isvedimas 2:        0.782688s

Test 2:
Failo skaitymas:    0.001563s
Failo rusiavimas:   0.103665s
Isvedimas 1:        1.124734s
Isvedimas 2:        0.784042s

1000000 nariu;

Test 1:
Failo skaitymas:    0.008533s
Failo rusiavimas:   1.025259s
Isvedimas 1:        13.449104s
Isvedimas 2:        9.666397s

Test 2:
Failo skaitymas:    0.004573s
Failo rusiavimas:   1.017613s
Isvedimas 1:        13.516770s
Isvedimas 2:        9.512492s

10000000 nariu;

Test 1:
Failo skaitymas:    0.027246s
Failo rusiavimas:   10.134857s
Isvedimas 1:        155.228354s
Isvedimas 2:        107.101697s

Test 2:
Failo skaitymas:    0.027599s
Failo rusiavimas:   10.354677s
Isvedimas 1:        155.345900s
Isvedimas 2:        106.634882s

# Sorting strategy test

1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai). Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu (įsitikinkite tuo!), tačiau šiame žingsnyje svarbiausia yra patyrinėti, kaip programos veikimo sparta priklauso nuo konteinerio tipo?
2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietiakai. Atminties atveju tai efektyviau, tačiau dažni trynimai gali būti "skausmingi", ypač tam tikro tipo konteineriams.
3 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant greičiausiai veikianti 1 arba 2 strategiją  įtraukiant į ją "efektyvius" darbo su konteineriais metodus (pateikiami žemiau).

1000 nariu;

Vector:
[1] Rusiavimas uztruko: 0.000511s
[2] Rusiavimas uztruko: 0.000341s
[3] Rusiavimas uztruko: 0.000400s

List:
[1] Rusiavimas uztruko: 0.001967s
[2] Rusiavimas uztruko: 0.000476s
[3] Rusiavimas uztruko: 0.000594s
 
Deque:
[1] Rusiavimas uztruko: 0.001066s
[2] Rusiavimas uztruko: 0.000798s
[3] Rusiavimas uztruko: 0.001218s

10000 nariu;

Vector:
[1] Rusiavimas uztruko: 0.004463s
[2] Rusiavimas uztruko: 0.002901s
[3] Rusiavimas uztruko: 0.003454s

List:
[1] Rusiavimas uztruko: 0.018267s
[2] Rusiavimas uztruko: 0.004796s
[3] Rusiavimas uztruko: 0.005777s

Deque:
[1] Rusiavimas uztruko: 0.010678s
[2] Rusiavimas uztruko: 0.007348s
[3] Rusiavimas uztruko: 0.010895s

100000 nariu;

Vector:
[1] Rusiavimas uztruko: 0.033779s
[2] Rusiavimas uztruko: 0.024354s
[3] Rusiavimas uztruko: 0.033387s

List:
[1] Rusiavimas uztruko: 0.174336s
[2] Rusiavimas uztruko: 0.040434s
[3] Rusiavimas uztruko: 0.049087s

Deque:
[1] Rusiavimas uztruko: 0.106251s
[2] Rusiavimas uztruko: 0.071745s
[3] Rusiavimas uztruko: 0.110910s

1000000 nariu;

Vector:
[1] Rusiavimas uztruko: 0.342680s
[2] Rusiavimas uztruko: 0.237894s
[3] Rusiavimas uztruko: 0.329903s

List:
[1] Rusiavimas uztruko: 1.799971s
[2] Rusiavimas uztruko: 0.400558s
[3] Rusiavimas uztruko: 0.474914s

Deque:
[1] Rusiavimas uztruko: 0.997032s
[2] Rusiavimas uztruko: 0.701040s
[3] Rusiavimas uztruko: 1.085049s

100000000 nariu;

Vector:
[1] Rusiavimas uztruko: 3.330945s
[2] Rusiavimas uztruko: 2.195973s
[3] Rusiavimas uztruko: 3.176460s

List:
[1] Rusiavimas uztruko: 17.550740s
[2] Rusiavimas uztruko: 3.913102s
[3] Rusiavimas uztruko: 4.766835s

Deque:
[1] Rusiavimas uztruko: 9.947796s
[2] Rusiavimas uztruko: 7.128626s
[3] Rusiavimas uztruko: 10.768384s

# Sorting strategy results

2 strategija buvo grečiausia strtegija iš visų, tačiau ji veikė greičiausiai su Vector ir lečiau su List ir Deque.
