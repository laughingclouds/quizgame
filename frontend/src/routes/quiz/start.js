import { useEffect, useState } from "react";
import { useSearchParams } from "react-router-dom";

export default function QuizStart() {
	let [questions, setQuestions] = useState([]);
	let [category, setCategory] = useState({});
	let [searchParams] = useSearchParams();

  const categoryId = searchParams.get("categoryId");

	useEffect(() => {
		console.log(`/api/categories/${categoryId}`);
		fetch(`/api/categories/${searchParams.get("categoryId")}`)
			.then((resp) => resp.json())
			.then((data) => {
				setCategory(data.category);
			});

		fetch(`/api/questions/${categoryId}`)
			.then((resp) => resp.json())
			.then((data) => {
				setQuestions(data.questions);
			});
	}, []);

	return (
		<>
			<h1>{category.Name}</h1>
			<h3>Start!</h3>

      <ul>
        <QuestionList questions={questions} />
      </ul>
		</>
	);
}

function QuestionList({questions}) {
  return questions.map((question) => {
    return (
      <li key={question.ID}>{question.Text}</li>
    );
  });
}
