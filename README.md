[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<div align="center">
  <a align="center">
    <img src="https://github.com/criogenox/E-Symbolic-Railway-Dynamics-Formulation/assets/53323058/4b126ff6-1d93-40ec-911c-9ffca3eb7abb.png" alt="Logo" width="700">
  </a>
  <h3 align="center">Railway applications &#x300A; E &#x300B;</h3>
  <p align="center">
    EridgeM: Bridging Formulas with Motion
  </p>
</div>

## About the project

<div align="justify">
  <p>
  
> The global goal: develop a tool to aid the process of complex mechanical systems' simulation, mainly focused on railway vehicles and especially, on articulated modular railcar models. It also enhances the ease of writing documentation, reports, and academic papers, where lengthy equations or complex mathematical expressions need to be used.
   </p>
       <p align="right">
    :muscle: don't let anyone get you down :muscle:
  </p> 

`Personal note:` figure uses Spanish language, cos I like that way. Thanks.
   <div>

## Current Status

<div align="justify">
  <p>

The initial phase of the project has been developed, which involves the functionality to `translate standard mathematical expressions`, used generally in dynamical formulations, into `LaTeX formatting`. The given developed tool will enable users to focus on analysis and interpretation, rather than formatting the result, by providing a seamless way to convert equations into a clear and visually appealing, and efficiently document their insights. 

`Currently features:`

- Support for derivatives, super/subscripts, special characters, and several operators. Detailed documentation for these features can be found in [here][eqsreadme-url].
   </p>
   <div>

### Conversion example

**`Raw input (from GiNaC output):`**

`4*C2*b*d_theta1-3*C153*d_phi1+7*a5^3*C3*d_phi1+C12*d_psi1-M1*axy^2*d2_theta1+a^2*C3*d_psi1+a*K1*d_xi1+c^2*am*C3*d_theta1-4*M2*b*d2_xi1-4*C*d_phi1+16*C7*d_psi1=0";`

**`Library LaTeX output:`**

<div>
<img src="https://latex.codecogs.com/svg.image?\inline&space;\LARGE&space;{\color{Red}-M_{1}a_{xy}^{2}\ddot{\theta}_{1}-4M_{2}b\ddot{\xi}_{1}&plus;4C_{2}b\dot{\theta}_{1}-3C_{153}\dot{\phi}_{1}&plus;7a_{5}^{3}C_{3}\dot{\phi}_{1}&plus;C_{12}\dot{\psi}_{1}&plus;a_{}^{2}C_{3}\dot{\psi}_{1}&plus;aK_{1}\dot{\xi}_{1}&plus;c_{}^{2}a_{m}C_{3}\dot{\theta}_{1}-4C\dot{\phi}_{1}&plus;16C_{7}\dot{\psi}_{1}=0}" title="{\color{Red}-M_{1}a_{xy}^{2}\ddot{\theta}_{1}-4M_{2}b\ddot{\xi}_{1}+4C_{2}b\dot{\theta}_{1}-3C_{153}\dot{\phi}_{1}+7a_{5}^{3}C_{3}\dot{\phi}_{1}+C_{12}\dot{\psi}_{1}+a_{}^{2}C_{3}\dot{\psi}_{1}+aK_{1}\dot{\xi}_{1}+c_{}^{2}a_{m}C_{3}\dot{\theta}_{1}-4C\dot{\phi}_{1}+16C_{7}\dot{\psi}_{1}=0}" />
</div>

<p align="right">(<a href="#top">back to top</a>)</p>

## Work in progress

<div align="justify">
  <p>
    
**`Direct conversion from GiNaC formulae`**
 
> The previous mentioned library [eqs2latex][eqssrc-url] takes as input the result of the processed expressions originated from the formulation of dynamical equations systems, represented in symbolic form using GiNaC C++ library.

- `Pursued objective:` generate a semi-automatic coded process to formulate the mechanical systems' equations of motion set, using modern C++
  
   </p>
   <div>

## Planned Features

<div align="justify">
  <p>
    
**`Numerical resolution of the formulated system (and other add-ons):`**
   
> Additionally, the upcoming aim to implement numerical solving capabilities for systems of equations using the Boost or Eigen C++ libraries, enabling users to fully set a practical analysis  of dynamical systems.
   </p>
   <div>

<!-- ROADMAP -->
## TODO

- [ ] 
- [ ] 
- [ ] 

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See [LICENSE.txt][license-url] for more information.

<!-- MARKDOWN LINKS & IMAGES -->
[linkedin-shield]: https://user-images.githubusercontent.com/53323058/230575198-fa1acbf4-8f82-4d8e-b245-3979276bc240.png
[linkedin-url]: https://www.linkedin.com/in/criogenox/
[eqsreadme-url]: https://github.com/criogenox/E-Symbolic-Railway-Dynamics-Formulation/tree/master/eqs2latex
[eqssrc-url]: https://github.com/criogenox/E-Symbolic-Railway-Dynamics-Formulation/tree/master/eqs2latex/src
[license-url]: https://github.com/criogenox/E-Symbolic-Railway-Dynamics-Formulation/tree/master?tab=MIT-1-ov-file
