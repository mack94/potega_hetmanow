# potega_hetmanow
Potęga Hetmanów - projekt z przedmiotu AdPTO

# Zadanie: Potęga Hetmanów 
## Opis: 

 Na szachownicy o rozmiarach <i>NxN</i> ustawiono pewną liczbę hetmanów. Każdy hetman dysponuje pewną potęgą określoną liczbą w postaci 2<sup>n</sup>, gdzie n ≥ 0. Hetman może zbić innego hetmana o tej samej potędze i wtedy jego potęga wzrasta dwukrotnie.

Należy znaleźć sekwencję ruchów, która redukuje liczbę hetmanów na szachownicy do liczby nie większej niż <i>K</i>

## Założenia:

 Należy założyć że:
<ul>
    <li>hetman może wykonywać ruchy jak w grze w szachy;</li>
    <li>szachownica ma rozmiar nie większy niż <i>128x128</i>;</li>
    <li>łączna potęga hetmanów na szachownicy jest mniejsza od 2<sup>60</sup>. </li>
</ul>

## Przykład: 

<img src="http://i.imgur.com/me59gju.png" />

Powyższy układ hetmanów należy zredukować do K=1 hetmana.

Rozwiązaniem jest sekwencja ruchów (współrzędne podane jako wiersz kolumna):

<ol>
    <li><strong>2 1 → 1 1</strong></li>
    <li><strong>0 1 → 1 0</strong></li>
    <li><strong>5 6 → 5 4</strong></li>
    <li><strong>3 1 → 2 2</strong></li>
    <li><strong>5 4 → 1 0</strong></li>
    <li><strong>1 1 → 1 0</strong></li>
    <li><strong>1 3 → 1 6</strong></li>
    <li><strong>1 0 → 1 2</strong></li>
    <li><strong>1 6 → 1 2</strong></li>
    <li><strong>2 2 → 1 2</strong></li>
</ol>


### Dane wejściowe:

Dane wejściowe należy wczytać ze standardowego wejścia formacie (opis zawartości kolejnych wierszy):

<pre>
[rozmiar szachownicy - N]
[liczba do której należy zredukować liczbę hetmanów - K]
[położenie hetmanów na szachownicy – N wierszy po N liczb, każda liczba jest wartością hetmana na danym polu lub zerem]
</pre>

Dla danych z rysunku plik ma postać:

<pre>
8
1
0    1    0    0    0    0    0    0
1    2    8    8    0    0    8    0
0    2   16    0    0    0    0    0
0   16    0    0    0    0    0    0
0    0    0    0    0    0    0    0
0    0    0    0    1    0    1    0
0    0    0    0    0    0    0    0
0    0    0    0    0    0    0    0
</pre>

### Wynik:

Rozwiązanie należy zapisać na standardowe wyjście jako kolejne wiersze opisujące kolejne ruchy (wiersz kolumna wiersz kolumna):

<pre>
2 1 1 1 
0 1 1 0 
5 6 5 4 
3 1 2 2 
5 4 1 0 
1 1 1 0 
1 3 1 6 
1 0 1 2 
1 6 1 2 
2 2 1 2
</pre>

Wiersze i kolumny na szachownicy są numerowane od 0. 

## Przykłady zadań:

***Uwaga: Nie wszystkie zadania jest w stanie rozwiązać (w sensownym czasie) zastosowany przeze mnie algorytm.***

<pre>
8
1
 0    1    2    1    1    0    0    0
 0    0    0    0    0    1    0    0
 0    0    0    0    0    0    0    0
 1    1    2    8    2    0    0    0
16    8    0    0   16    0    0    0
 0    0    0    0    0    0    0    0
 1    0    1    0    0    0    0    1
 0    1    0    0    0    0    0    0
</pre>

<pre>
8
2
16    0    0    1    8    8    4    0
 0    0    0    0    1    0    0    0
 0    0    0    0    2    0    0    0
 0    0    0    2    0    1    0    1
16    0   16    0    0    0    0    0
 0    0    2    0    0    0    0    2
32    1    0    1    0    0    2    4
 0   64    0    0    4    0    0    4
</pre>

<pre>
8
3
16   16    8    0   32    0    0    4
16    0    0   32    4    4    2    4
 8   16    0    0    8    0    0    8
16    0    0    0    0    0    0   16
 0    4    0    2    0    4   16   16
16    0    0    0    0    2    2   32
 2    0    0    0    0    1    1    8
 0   64   32    0    4   16   16    0
</pre>


 <pre>
 8
 4
 0    0    1   16   16   64    8   16
 4    1    0    1    2    0    8   16
 4    0    1    0    8   16    4   16
 0    0    1    8    8    2    8    8
64    1    8   64    2    2    1    8
16   32    2    1    0    1    2    0
 4    1    4    8    1    0    0    4
 1    1    1    2    8    0    4   32
</pre>

## Dodatkowe informacje, programy i dane: 

Dodatkowe programy i informacje zostana udostepnione pozniej.

<ul>
    <li>Program sędziego: <a href="http://home.agh.edu.pl/~faliszew/atpo2016/judge.zip">judge.zip</a> </li>
</ul>    

Program sedziego został zaimplementowany w języku Python, dla interpreterów z rodziny 2.7. Sędzie potrafi także rysować plansze. Aby włączyć tę opcję należy w jego kodzie ustawić zmienną viewer na True.

Wywołanie sędziego:

  <code>python judge.py input output</code>

gdzie <i>input</i> to opis planszy z zadaniem, a <i>output</i> to opis planszy z rozwiązaniem. 

### The original homework description:

http://home.agh.edu.pl/~faliszew/atpo2016/
