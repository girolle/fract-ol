# fract-ol

<img src="https://github.com/girolle/fract-ol/blob/master/images/Screenshot%20from%202020-04-09%2022-27-58.png">
<h4> Программа для генерации и отрисовки фракталов</h4>
<p> Отрисовка происходит плавно и в реальном времени, используя координаты курсора в качестве "бассейна притяжения". <br>
Реализованы 6 типов фракталов, в том числе множества Мандельброта и Жулия</p>
<h4>Возможности</h4>
<p>- движение по изображению (используя клавиши ASWD)<br>
- изменение цветовой раскрасски степеней вхождения (10 вариантов, используя цифры клавиатуры) <br>
- увеличение до 6.8 млн раз (колесиком мышки, следует за курсором)</p> <br>
Остановить генерацию можно, нажав левой клавишей мыши.<br>
R - возврат к начальнуму положению <br>
Esc - выход из программы<br><br>
<p> Написано на языке С, с использованием библиотеки MinilibX и собсвенной библиотеки функций.<br>
Отсутсвуют утечки памяти и непредсказуемые вылеты (segmentation fault, bus error, double free, etc)<br>
Работает на Mac OS Sierra, поддержка других версий Mac OS неизвестна</p>
<h5>usage:</h5>
> make<br>
> ./fractol 2<br>
<h4> Примеры использования:</h4>
<img src="https://github.com/girolle/fract-ol/blob/master/images/Screenshot%20from%202020-04-09%2022-35-25.png">
<img src="https://github.com/girolle/fract-ol/blob/master/images/Screenshot%20from%202020-04-09%2022-36-50.png">
<img src="https://github.com/girolle/fract-ol/blob/master/images/Screenshot%20from%202020-04-09%2022-38-11.png">
<img src="https://github.com/girolle/fract-ol/blob/master/images/Screenshot%20from%202020-04-09%2023-01-43.png">
