<?php

class context_title_reaction extends context_reaction {

  function options_form($context) {
    $settings = $this->fetch_from_context($context);
    $form = array(
      '#title' => 'Configure Node Title',
      '#type' => 'fieldset'
    );
    $form['title_off'] = array(
      '#title' => 'Turn off title',
      '#description' => 'Turn off the title in the node template',
      '#type' => 'checkbox',
      '#default_value' => isset($settings['title_off'])? $settings['title_off'] : 0,
    );
    $form['title_override'] = array(
      '#title' => 'Override title',
      '#description' => 'Change the title',
      '#type' => 'textfield',
      '#default_value' => isset($settings['title_override'])? $settings['title_override'] : '',
    );
    return $form;
  }

  function execute(&$vars) {
    $vars['title'] = $this->get_title($vars['title']);
  }
  function get_title($title) {
    foreach ($this->get_contexts() as $context) {
      if (isset($context->reactions[$this->plugin])) {
        $settings = $context->reactions[$this->plugin];
        $title = $settings['title_off'] ? FALSE : $settings['title_override'];
      }
    }
    return $title;
  }
}
