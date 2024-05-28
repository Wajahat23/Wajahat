let slideIndex = 0;
showSlide(slideIndex);

function changeSlide(n) {
    showSlide((slideIndex += n) % 3);
}

function showSlide(n) {
    const slides = document.querySelectorAll(".slide");
    slides.forEach((slide) => (slide.style.display = "none"));
    slides[n].style.display = "block";
}