<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Validar campos
    $nombre = $_POST["nombre"];
    $telefono = $_POST["telefono"];
    $email = $_POST["email"];
    $mensaje = $_POST["mensaje"];

    if (empty($nombre) || empty($telefono) || empty($email) || empty($mensaje)) {
        // Mostrar mensaje de error si algún campo está vacío
        $error_message = "Por favor, complete todos los campos del formulario.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        // Mostrar mensaje de error si el correo electrónico no es válido
        $error_message = "Por favor, introduzca una dirección de correo electrónico válida.";
    } else {
        // Enviar correo electrónico
        $destinatario = "infinitie.soft.iv@gmail.com";
        $asunto = "Nuevo mensaje de contacto desde tu página web";
        $contenido = "Nombre: $nombre\n";
        $contenido .= "Teléfono: $telefono\n";
        $contenido .= "Correo electrónico: $email\n";
        $contenido .= "Mensaje:\n$mensaje";

        if (mail($destinatario, $asunto, $contenido)) {
            // Redireccionar a la página de gracias si el correo se envió correctamente
            header("Location: gracias.html");
            exit;
        } else {
            // Mostrar mensaje de error si hubo un problema al enviar el correo
            $error_message = "Se produjo un error al enviar el formulario. Por favor, inténtelo de nuevo más tarde.";
        }
    }
}
?>